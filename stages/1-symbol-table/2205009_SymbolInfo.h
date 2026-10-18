#pragma once

#include<iostream>
#include<string>

using namespace std;

class SymbolInfo{
private:
    string symbolName;
    string symbolType;
    SymbolInfo* next;
    string returnType;
    SymbolInfo** params;
    int pcnt;
public:
    SymbolInfo(string name, string type){
        symbolName = name;
        symbolType = type;
        next = NULL;
        returnType = "";
        params = NULL;
        pcnt = 0;
    }
    SymbolInfo(string name, string type, string retType, SymbolInfo** parameters, int cnt){
        symbolName = name;
        symbolType = type;
        next = NULL;
        returnType = retType;
        params = parameters;
        pcnt = cnt;
    }
    SymbolInfo(string name, string type, SymbolInfo** parameters, int cnt){
        symbolName = name;
        symbolType = type;
        next = NULL;
        returnType = "";
        params = parameters;
        pcnt = cnt;
    }
    ~SymbolInfo(){
        for(int i = 0; i < pcnt; i++){
            delete params[i];
        }
        delete[] params;
        delete next;
    }
    string getName(){
        return symbolName;
    }
    string getType(){
        return symbolType;
    }
    SymbolInfo* getNext(){
        return next;
    }
    void setNext(SymbolInfo* nextSymbol){
        next = nextSymbol;
    }
    void setName(string name){
        symbolName = name;
    }
    void setType(string type){
        symbolType = type;
    }
    string getReturnType(){
        return returnType;
    }
    void setReturnType(string retType){
        returnType = retType;
    }
    void addParameter(SymbolInfo* param){
        if(params == NULL){
            params = new SymbolInfo*[1];
            params[0] = param;
            pcnt = 1;
        }
        else{
            SymbolInfo** newParams = new SymbolInfo*[pcnt + 1];
            for(int i = 0; i < pcnt; i++){
                newParams[i] = params[i];
            }
            newParams[pcnt] = param;
            delete[] params;
            params = newParams;
            pcnt++;
        }
    }

    void printSymbolInfo(){
        if(symbolType == "FUNCTION"){
            cout << "<" << symbolName << "," << symbolType << "," << returnType << "<==(";
            for(int i = 0; i < pcnt; i++){
                cout << params[i]->getType();
                if(i != pcnt - 1){
                    cout << ",";
                }
            }
            cout << ")>";
        }
        else if(symbolType == "STRUCT" || symbolType == "UNION"){
            cout << "<" << symbolName << "," << symbolType << ",{";
            for(int i = 0; i < pcnt; i++){
                cout << "(" << params[i]->getName() << "," << params[i]->getType() << ")";
                if(i != pcnt - 1){
                    cout << ",";
                }
            }
            cout << "}>";
        }
        else{
            cout << "<" << symbolName << "," << symbolType << ">";
        }
    }
};