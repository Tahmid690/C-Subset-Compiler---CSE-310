#!/bin/bash

# ==============================================================================
#  C-Subset Compiler - Complete Automated Verification Test Suite
# ==============================================================================
#  Usage: bash tests/verify.sh [compiler_binary]
#  Default compiler binary: ./bin/csubset
# ==============================================================================

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"

COMPILER_ARG="${1:-$ROOT_DIR/bin/csubset}"
if [[ "$COMPILER_ARG" = /* ]]; then
    COMPILER="$COMPILER_ARG"
else
    COMPILER="$(pwd)/$COMPILER_ARG"
fi
PRINTLIB="$ROOT_DIR/lib/printProc.lib"
TEST_SUITE_DIR="$SCRIPT_DIR/test_suite"
SAMPLE_CASES_DIR="$SCRIPT_DIR/sample_cases"
TMPDIR="$SCRIPT_DIR/.verify_tmp"

GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
CYAN='\033[0;36m'
BOLD='\033[1m'
NC='\033[0m'

if [ ! -f "$COMPILER" ]; then
    echo -e "${RED}[ERROR]${NC} Compiler binary not found at $COMPILER"
    echo "Please build the project first using: make"
    exit 1
fi

if ! command -v fasm &> /dev/null; then
    echo -e "${RED}[ERROR]${NC} 'fasm' (Flat Assembler) is not installed or not in PATH."
    echo "Install it via: sudo apt install fasm"
    exit 1
fi

mkdir -p "$TMPDIR"
cp "$PRINTLIB" "$TMPDIR/"
export INCLUDE="$ROOT_DIR/lib:$INCLUDE"

PASS=0
FAIL=0
TOTAL=0

cleanup() {
    rm -rf "$TMPDIR"
}
trap cleanup EXIT

# ── Expected outputs for test_suite ──────────────────────────────────────────
declare -A EXPECTED

EXPECTED["exp.c"]="2
1"

EXPECTED["func.c"]="5"

EXPECTED["loop.c"]="-1
12
1"

EXPECTED["recursion1_i.c"]="63"

EXPECTED["recursion2_i.c"]="28"

EXPECTED["test1_i.c"]="1
13
27
0
1
1
1
1
2
-2"

EXPECTED["test2_i.c"]="8
6
3"

EXPECTED["test3_i.c"]="0
1
2
3
4
5
18
0
18
-1"

EXPECTED["test4_i.c"]="7
8
32
170"

EXPECTED["test5_i.c"]="25
0
14
4"

EXPECTED["test6_i.c"]="-2
-2
-1
-1
100"

EXPECTED["test7_i.c"]="600"

EXPECTED["corner1_i.c"]="-2
1
1
0
1"

EXPECTED["corner2_i.c"]="14
6
5"

EXPECTED["corner3_i.c"]="0
4
16
20"

EXPECTED["corner4_i.c"]="6
6"

EXPECTED["corner5_i.c"]="15
5
12
13"

EXPECTED["corner6_i.c"]="55
10
9"

EXPECTED["corner7_i.c"]="6
5
4
5
7
4
3"

EXPECTED["corner8_i.c"]="60
99
11"

EXPECTED["corner9_i.c"]="7
10
5
1
10
6"

EXPECTED["corner10_i.c"]="1
0
0
1
21"

echo ""
echo -e "${BOLD}${CYAN}================================================================${NC}"
echo -e "${BOLD}${CYAN}            C-Subset Compiler Automated Test Suite              ${NC}"
echo -e "${BOLD}${CYAN}================================================================${NC}"
echo -e " Compiler: ${BOLD}$COMPILER${NC}"
echo ""

echo -e "${BOLD}Part 1: Running Benchmark & Corner Cases (22 tests)...${NC}"
echo "----------------------------------------------------------------"

for f in "$TEST_SUITE_DIR"/*.c; do
    [ -e "$f" ] || continue
    name=$(basename "$f")
    TOTAL=$((TOTAL + 1))

    if [ -z "${EXPECTED[$name]+_}" ]; then
        echo -e "${YELLOW}[SKIP]${NC}  $name  (no expected output defined)"
        continue
    fi

    # Compile source with csubset
    (cd "$TMPDIR" && LD_LIBRARY_PATH=/usr/local/lib "$COMPILER" "$f" > /dev/null 2>&1)
    if [ ! -f "$TMPDIR/code.asm" ]; then
        echo -e "${RED}[FAIL]${NC}  $name  => COMPILER CRASHED"
        FAIL=$((FAIL + 1))
        continue
    fi

    # Assemble with FASM
    (cd "$TMPDIR" && fasm optimized_code.asm out.elf > /dev/null 2>&1)
    if [ ! -f "$TMPDIR/out.elf" ]; then
        # Try unoptimized if optimized failed
        (cd "$TMPDIR" && fasm code.asm out.elf > /dev/null 2>&1)
    fi

    if [ ! -f "$TMPDIR/out.elf" ]; then
        echo -e "${RED}[FAIL]${NC}  $name  => FASM ASSEMBLE FAILED"
        FAIL=$((FAIL + 1))
        continue
    fi

    chmod +x "$TMPDIR/out.elf"
    ACTUAL=$("$TMPDIR/out.elf" 2>&1)
    EXPECT="${EXPECTED[$name]}"

    if [ "$ACTUAL" = "$EXPECT" ]; then
        echo -e " ${GREEN}PASS${NC}  $name"
        PASS=$((PASS + 1))
    else
        echo -e " ${RED}FAIL${NC}  $name"
        echo "       Expected: $(echo "$EXPECT" | tr '\n' ' ')"
        echo "       Got:      $(echo "$ACTUAL" | tr '\n' ' ')"
        FAIL=$((FAIL + 1))
    fi

    rm -f "$TMPDIR/code.asm" "$TMPDIR/optimized_code.asm" "$TMPDIR/out.elf" "$TMPDIR/lexLogFile.txt"
done

echo ""
echo -e "${BOLD}Part 2: Running Extended Unit Tests (17 tests)...${NC}"
echo "----------------------------------------------------------------"

for f in "$SAMPLE_CASES_DIR"/*.c; do
    [ -e "$f" ] || continue
    name=$(basename "$f")
    base="${name%.c}"

    exp_file=""
    if [ -f "$SAMPLE_CASES_DIR/${base}_output_gpp.txt" ]; then
        exp_file="$SAMPLE_CASES_DIR/${base}_output_gpp.txt"
    elif [ -f "$SAMPLE_CASES_DIR/${base}_expected.txt" ]; then
        exp_file="$SAMPLE_CASES_DIR/${base}_expected.txt"
    else
        continue
    fi

    TOTAL=$((TOTAL + 1))

    (cd "$TMPDIR" && LD_LIBRARY_PATH=/usr/local/lib "$COMPILER" "$f" > /dev/null 2>&1)
    if [ ! -f "$TMPDIR/code.asm" ]; then
        echo -e "${RED}[FAIL]${NC}  $name  => COMPILER CRASHED"
        FAIL=$((FAIL + 1))
        continue
    fi

    (cd "$TMPDIR" && fasm optimized_code.asm out.elf > /dev/null 2>&1)
    if [ ! -f "$TMPDIR/out.elf" ]; then
        (cd "$TMPDIR" && fasm code.asm out.elf > /dev/null 2>&1)
    fi

    if [ ! -f "$TMPDIR/out.elf" ]; then
        echo -e "${RED}[FAIL]${NC}  $name  => FASM ASSEMBLE FAILED"
        FAIL=$((FAIL + 1))
        continue
    fi

    chmod +x "$TMPDIR/out.elf"
    ACTUAL=$("$TMPDIR/out.elf" 2>&1)
    EXPECT=$(cat "$exp_file")

    if [ "$ACTUAL" = "$EXPECT" ]; then
        echo -e " ${GREEN}PASS${NC}  $name"
        PASS=$((PASS + 1))
    else
        echo -e " ${RED}FAIL${NC}  $name"
        echo "       Expected: $(echo "$EXPECT" | tr '\n' ' ')"
        echo "       Got:      $(echo "$ACTUAL" | tr '\n' ' ')"
        FAIL=$((FAIL + 1))
    fi

    rm -f "$TMPDIR/code.asm" "$TMPDIR/optimized_code.asm" "$TMPDIR/out.elf" "$TMPDIR/lexLogFile.txt"
done

echo ""
echo -e "${BOLD}${CYAN}================================================================${NC}"
if [ $FAIL -eq 0 ]; then
    echo -e "  ${BOLD}${GREEN}ALL TESTS PASSED! (${PASS}/${TOTAL})${NC}"
else
    echo -e "  ${BOLD}Results: ${GREEN}${PASS} PASSED${NC} / ${RED}${FAIL} FAILED${NC} / ${TOTAL} TOTAL"
fi
echo -e "${BOLD}${CYAN}================================================================${NC}"
echo ""

if [ $FAIL -gt 0 ]; then
    exit 1
fi
exit 0
