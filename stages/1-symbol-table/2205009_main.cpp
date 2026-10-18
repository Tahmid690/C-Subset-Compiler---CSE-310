#include<iostream>
#include<string>
#include<sstream>
#include "2205009_ScopeTable.h"
#include "2205009_SymbolTable.h"
#include "2205009_SymbolInfo.h"

using namespace std;

void printcmd(int cnt,string cmd){
    cout << "Cmd " << cnt << ":";
    string tmp = cmd;
    stringstream ss(tmp);
    while(ss >> tmp){
        cout << " ";    
        cout << tmp;
    }
    cout << endl;
}

int main(int argc, char* argv[]){
    freopen(argv[1], "r", stdin);
    freopen(argv[2], "w", stdout);

    int n;
    cin >> n;
    SymbolTable* st = new SymbolTable(n);

    int scopes = 1;

    string cmd;
    getline(cin, cmd);
    int cnt = 0;

    while(getline(cin, cmd)){
        
        
        string opcode;
        stringstream tokens(cmd);
        tokens >> opcode;

        if(opcode == "I"){

            printcmd(++cnt, cmd);

            string symbolName,symbolType;
            tokens >> symbolName >> symbolType;
            SymbolInfo *r = new SymbolInfo(symbolName, symbolType);


            if(symbolName.empty() || symbolType.empty()){
                delete r;
                cout << "\tNumber of parameters mismatch for the command I" << endl;
                continue;
            }
            if(symbolType == "FUNCTION"){
                string returnType;
                tokens >> returnType;
                if(returnType.empty()){
                    delete r;
                    cout << "\tNumber of parameters mismatch for the command I" << endl;
                    continue;
                }
                r->setReturnType(returnType);
                
                string ptype;
                while(tokens >> ptype){
                    SymbolInfo* param = new SymbolInfo("", ptype);
                    r->addParameter(param);
                }
            }
            else if(symbolType == "STRUCT" || symbolType == "UNION"){
                int flg = 0;
                string pname;
                while(tokens >> pname){
                    string ptype;
                    if(!(tokens >> ptype)){
                        delete r;
                        flg = 1;
                        cout << "\tNumber of parameters mismatch for the command I" << endl;
                        break;
                    }
                    SymbolInfo* param = new SymbolInfo(pname, ptype);
                    r->addParameter(param);
                }
                if(flg == 1){
                    continue;
                }
            }
            else{
                string tmp;
                if(tokens >> tmp){
                    delete r;
                    cout << "\tNumber of parameters mismatch for the command I" << endl;
                    continue;
                }
            }

            int idx,pos,scope_id;
            if(st->insert(r, idx, pos, scope_id)){
                cout << "\tInserted in ScopeTable# " << scope_id << " at position " << idx+1 <<  ", " << pos+1 << endl;
            }
            else{
                delete r;
                cout << "\t'" << symbolName << "'" << " already exists in the current ScopeTable" << endl;
            }

        }
        else if(opcode == "L"){
            printcmd(++cnt, cmd);
            string symbolName;
            int chk = 0;
            while(tokens >> symbolName){
                chk++;    
            }

            if(symbolName.empty()){
                cout << "\tNumber of parameters mismatch for the command L" << endl;
                continue;
            }
            
            if(chk>1){
                cout << "\tNumber of parameters mismatch for the command L" << endl;
                continue;
            }
            int idx,pos,scope_id;
            if(st->lookup(symbolName, idx, pos, scope_id) != NULL){
                cout << "\t'" << symbolName << "'" << " found in ScopeTable# " << scope_id << " at position " << idx+1 <<  ", " << pos+1 << endl;
            }
            else{
                cout << "\t'" << symbolName << "'" << " not found in any of the ScopeTables" << endl;
            }
        }
        else if(opcode == "D"){
            printcmd(++cnt, cmd);
            string symbolName;
            int chk = 0;
            while(tokens >> symbolName){
                chk++;    
            }

            if(symbolName.empty()){
                cout << "\tNumber of parameters mismatch for the command D" << endl;
                continue;
            }
            
            if(chk>1){
                cout << "\tNumber of parameters mismatch for the command D" << endl;
                continue;
            }
            int idx,pos,scope_id;
            if(st->remove(symbolName, idx, pos, scope_id)){
                cout << "\tDeleted '" << symbolName << "' from ScopeTable# " << scope_id << " at position " << idx+1 <<  ", " << pos+1 << endl;
            }
            else{
                cout << "\tNot found in the current ScopeTable" << endl;
            }
        }
        else if(opcode == "P"){
            string typ;
            int chk = 0;
            while(tokens >> typ){
                chk++;    
            }

            if(typ.empty()){
                printcmd(++cnt, cmd);
                cout << "\tNumber of parameters mismatch for the command P" << endl;
                continue;
            }
            if(chk>1){
                printcmd(++cnt, cmd);
                cout << "\tNumber of parameters mismatch for the command P" << endl;
                continue;
            }
            if(typ == "A"){
                printcmd(++cnt, cmd);
                st->printAll();
            }
            else if(typ == "C"){
                printcmd(++cnt, cmd);
                st->printCurrent();
            }
            else{
                // cout << "\tInvalid parameter for the command P" << endl;
                continue;
            }
            
        }
        else if(opcode == "S"){
            string tmp;
            if(tokens >> tmp){
                printcmd(++cnt, cmd);
                cout << "\tNumber of parameters mismatch for the command S" << endl;
                continue;
            }
            else{
                printcmd(++cnt, cmd);
                st->enterScope(n,++scopes);
            }
        }
        else if(opcode == "E"){
            string tmp;
            if(tokens >> tmp){
                printcmd(++cnt, cmd);
                cout << "\tNumber of parameters mismatch for the command E" << endl;
                continue;
            }
            else{
                if(st->getCurrentScope()->getParentScope() != NULL){
                    printcmd(++cnt, cmd);
                    st->exitScope();
                }
            }
        }
        else if(opcode == "Q"){
            printcmd(++cnt, cmd);
            delete st;
            return 0;
        }
        else{
            continue;
        }

    }

    delete st;
}
    