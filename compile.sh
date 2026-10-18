#!/bin/bash

# ==============================================================================
#  C-Subset Compiler - End-to-End Compilation Driver
# ==============================================================================
#  Translates a C-subset source file into a standalone Linux ELF executable
#  Pipeline: C Source -> ANTLR4 AST -> x86 Assembly -> Peephole Optimizer -> FASM -> ELF Binary
#
#  Usage:
#    ./compile.sh <source.c> [options]
#
#  Options:
#    -o <outfile>     Specify the output executable name (default: <source_basename>)
#    --run            Execute the binary immediately after compilation
#    --no-opt         Assemble unoptimized assembly (code.asm) instead of optimized
#    --asm-only       Stop after generating assembly files (.asm)
#    -h, --help       Show this help message
# ==============================================================================

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BIN_COMPILER="$SCRIPT_DIR/bin/csubset"
LIB_DIR="$SCRIPT_DIR/lib"

GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
CYAN='\033[0;36m'
BOLD='\033[1m'
NC='\033[0m'

show_help() {
    echo -e "${BOLD}C-Subset Compiler Driver${NC}"
    echo "Usage: $0 <source.c> [options]"
    echo ""
    echo "Options:"
    echo "  -o <outfile>   Specify output executable name (default: ./<source_basename>)"
    echo "  --run          Run the generated executable immediately"
    echo "  --no-opt       Use unoptimized assembly instead of peephole-optimized assembly"
    echo "  --asm-only     Only generate assembly (code.asm and optimized_code.asm)"
    echo "  -h, --help     Show this help message"
    echo ""
    echo "Example:"
    echo "  $0 tests/test_suite/test1_i.c -o test1 --run"
}

if [ $# -eq 0 ]; then
    show_help
    exit 1
fi

INPUT_FILE=""
OUTPUT_FILE=""
RUN_AFTER=0
USE_OPT=1
ASM_ONLY=0

while [ $# -gt 0 ]; do
    case "$1" in
        -h|--help)
            show_help
            exit 0
            ;;
        -o)
            shift
            OUTPUT_FILE="$1"
            ;;
        --run)
            RUN_AFTER=1
            ;;
        --no-opt)
            USE_OPT=0
            ;;
        --asm-only)
            ASM_ONLY=1
            ;;
        *)
            if [ -z "$INPUT_FILE" ]; then
                INPUT_FILE="$1"
            else
                echo -e "${RED}[Error]${NC} Unexpected argument: $1"
                show_help
                exit 1
            fi
            ;;
    esac
    shift
done

if [ -z "$INPUT_FILE" ]; then
    echo -e "${RED}[Error]${NC} No input C file specified."
    exit 1
fi

if [ ! -f "$INPUT_FILE" ]; then
    echo -e "${RED}[Error]${NC} Input file not found: $INPUT_FILE"
    exit 1
fi

# Ensure compiler binary is built
if [ ! -f "$BIN_COMPILER" ]; then
    echo -e "${CYAN}[Info]${NC} Compiler binary not found. Building with make..."
    make -C "$SCRIPT_DIR" csubset
fi

# Ensure FASM is installed
if [ $ASM_ONLY -eq 0 ] && ! command -v fasm &> /dev/null; then
    echo -e "${RED}[Error]${NC} Flat Assembler ('fasm') is required to generate executables."
    echo "Install it via: sudo apt install fasm"
    exit 1
fi

# Set default output file name
BASE_NAME="$(basename "$INPUT_FILE")"
BASE_NO_EXT="${BASE_NAME%.*}"
if [ -z "$OUTPUT_FILE" ]; then
    OUTPUT_FILE="./$BASE_NO_EXT"
fi

# Set up FASM include path
if [ -n "$INCLUDE" ]; then
    export INCLUDE="$LIB_DIR:$INCLUDE"
else
    export INCLUDE="$LIB_DIR"
fi

# Ensure printProc.lib is also in current directory for direct fasm invocations
if [ ! -f "printProc.lib" ] && [ -f "$LIB_DIR/printProc.lib" ]; then
    cp "$LIB_DIR/printProc.lib" .
fi

echo -e "${CYAN}==>${NC} Compiling ${BOLD}$INPUT_FILE${NC}..."
LD_LIBRARY_PATH=/usr/local/lib "$BIN_COMPILER" "$INPUT_FILE"

if [ ! -f "code.asm" ]; then
    echo -e "${RED}[Error]${NC} Compilation failed to produce code.asm"
    exit 1
fi

echo -e " ${GREEN}✔${NC} Generated assembly: ${BOLD}code.asm${NC} & ${BOLD}optimized_code.asm${NC}"

if [ $ASM_ONLY -eq 1 ]; then
    echo -e "${GREEN}[Success]${NC} Assembly generated successfully."
    exit 0
fi

ASM_TARGET="optimized_code.asm"
if [ $USE_OPT -eq 0 ]; then
    ASM_TARGET="code.asm"
    echo -e "${YELLOW}[Info]${NC} Using unoptimized assembly ($ASM_TARGET)"
fi

echo -e "${CYAN}==>${NC} Assembling with FASM into ${BOLD}$OUTPUT_FILE${NC}..."
fasm "$ASM_TARGET" "$OUTPUT_FILE" > /dev/null
chmod +x "$OUTPUT_FILE"

echo -e " ${GREEN}✔${NC} Executable built: ${BOLD}$OUTPUT_FILE${NC}"

if [ $RUN_AFTER -eq 1 ]; then
    echo -e "${CYAN}==>${NC} Executing ${BOLD}$OUTPUT_FILE${NC}:"
    echo "----------------------------------------------------"
    "$OUTPUT_FILE"
    echo "----------------------------------------------------"
fi
