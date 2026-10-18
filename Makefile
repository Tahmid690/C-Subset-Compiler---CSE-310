# ==============================================================================
#  C-Subset Compiler Makefile
# ==============================================================================

CXX      ?= g++
CXXFLAGS ?= -std=c++17 -O2 -w
ANTLR_JAR = lib/antlr-4.13.2-complete.jar

# ANTLR runtime headers and libraries (supports both /usr/local and /usr)
INCLUDES  = -I/usr/local/include/antlr4-runtime -I/usr/include/antlr4-runtime
LDFLAGS   = -L/usr/local/lib -L/usr/lib -lantlr4-runtime -pthread -Wl,-rpath,/usr/local/lib

BIN_DIR   = bin
BUILD_DIR = build

COMPILER_SRC_DIR = src/compiler
ANALYZER_SRC_DIR = src/analyzer

COMPILER_SRCS    = $(wildcard $(COMPILER_SRC_DIR)/*.cpp)
ANALYZER_SRCS    = $(wildcard $(ANALYZER_SRC_DIR)/*.cpp)

TARGET_COMPILER  = $(BIN_DIR)/csubset
TARGET_ANALYZER  = $(BIN_DIR)/csubset-analyzer

.PHONY: all csubset analyzer grammar test clean

all: $(TARGET_COMPILER) $(TARGET_ANALYZER)
	@echo "Build complete. Executables available in $(BIN_DIR)/"

# Compile main C-Subset Compiler
$(TARGET_COMPILER): $(COMPILER_SRCS)
	@mkdir -p $(BIN_DIR)
	@echo "Compiling C-Subset Compiler ($(TARGET_COMPILER))..."
	$(CXX) $(CXXFLAGS) -I$(COMPILER_SRC_DIR) $(INCLUDES) $(COMPILER_SRCS) $(LDFLAGS) -o $@

# Compile Syntax & Semantic Analyzer
$(TARGET_ANALYZER): $(ANALYZER_SRCS)
	@mkdir -p $(BIN_DIR)
	@echo "Compiling Syntax & Semantic Analyzer ($(TARGET_ANALYZER))..."
	$(CXX) $(CXXFLAGS) -I$(ANALYZER_SRC_DIR) $(INCLUDES) $(ANALYZER_SRCS) $(LDFLAGS) -o $@

# Regenerate ANTLR C++ visitor & lexer/parser from .g4 grammars
grammar:
	@if [ -f "$(ANTLR_JAR)" ]; then \
		echo "Regenerating compiler grammar using $(ANTLR_JAR)..."; \
		java -jar $(ANTLR_JAR) -Dlanguage=Cpp -visitor -no-listener -o $(COMPILER_SRC_DIR) $(COMPILER_SRC_DIR)/CSubset_2205009.g4; \
		echo "Regenerating analyzer grammar using $(ANTLR_JAR)..."; \
		java -jar $(ANTLR_JAR) -Dlanguage=Cpp -visitor -no-listener -o $(ANALYZER_SRC_DIR) $(ANALYZER_SRC_DIR)/CSubset_2205009.g4; \
	elif command -v antlr4 &> /dev/null; then \
		echo "Regenerating compiler grammar using system antlr4..."; \
		antlr4 -Dlanguage=Cpp -visitor -no-listener -o $(COMPILER_SRC_DIR) $(COMPILER_SRC_DIR)/CSubset_2205009.g4; \
		echo "Regenerating analyzer grammar using system antlr4..."; \
		antlr4 -Dlanguage=Cpp -visitor -no-listener -o $(ANALYZER_SRC_DIR) $(ANALYZER_SRC_DIR)/CSubset_2205009.g4; \
	else \
		echo "Error: Neither $(ANTLR_JAR) nor 'antlr4' command found."; \
		exit 1; \
	fi

# Run the complete test suite
test: $(TARGET_COMPILER)
	@bash tests/verify.sh $(TARGET_COMPILER)

# Clean build artifacts
clean:
	@echo "Cleaning build artifacts..."
	rm -rf $(BIN_DIR) $(BUILD_DIR) *.out *.elf code.asm optimized_code.asm glb.txt lexLogFile.txt log.txt error.txt tests/.verify_tmp
