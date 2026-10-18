#include <iostream>
#include <fstream>
#include <string>
#include "antlr4-runtime.h"
#include "CSubset_2205009Lexer.h"
#include "CSubset_2205009Parser.h"
#include "TreeVisitor.h"
#include "2205009_Optimizer.h"

using namespace antlr4;
using namespace std;

ofstream lexLogFile; 

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        cerr << "Error opening input file: " << argv[1] << endl;
        return 1;
    }

    ANTLRInputStream input(inputFile);
    CSubset_2205009Lexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    CSubset_2205009Parser parser(&tokens);

    CSubset_2205009Parser::StartContext* tree = parser.start();
    TreeVisitor visitor;
    visitor.visit(tree);
    
    cout << "Parsing completed." << endl;

    optimizer("code.asm", "optimized_code.asm");

    inputFile.close();
    return 0;
}
