#pragma once

#include <iostream>
#include <string>

using namespace std;

class SymbolInfo {
private:
    string symbolName;
    string symbolType;
    SymbolInfo* next;

    string varType;       
    bool isArr;
    int arrSz;
    bool isFunction;
    bool isDefined;
    string retType;    

    string* paramTypes;
    string* paramNames;
    int paramCount;

    SymbolInfo** params;
    int pcnt;

public:
    SymbolInfo(string name, string type) {
        symbolName = name;
        symbolType = type;
        next = NULL;
        varType = "";
        isArr = false;
        arrSz = 0;
        isFunction = false;
        isDefined = false;
        retType = "";
        paramTypes = NULL;
        paramNames = NULL;
        paramCount = 0;
        params = NULL;
        pcnt = 0;
    }

    SymbolInfo(string name, string type, string rType, SymbolInfo** parameters, int cnt) {

        symbolName = name;
        symbolType = type;
        next = NULL;
        varType = "";
        isArr = false;
        arrSz = 0;
        isFunction = true;
        isDefined = false;
        retType = rType;

        paramTypes = NULL;
        paramNames = NULL;
        paramCount = 0;
        params = parameters;
        pcnt = cnt;
    }

    SymbolInfo(string name, string type, SymbolInfo** parameters, int cnt) {
        symbolName = name;
        symbolType = type;
        next = NULL;
        varType = "";
        isArr = false;
        arrSz = 0;
        isFunction = true;
        isDefined = false;
        retType = "";
        paramTypes = NULL;
        paramNames = NULL;
        paramCount = 0;
        params = parameters;
        pcnt = cnt;
    }

    ~SymbolInfo() {
        if (paramTypes != NULL) delete[] paramTypes;
        if (paramNames != NULL) delete[] paramNames;
        if (params != NULL) {
            for (int i = 0; i < pcnt; i++) {
                if (params[i] != NULL) delete params[i];
            }
            delete[] params;
        }
        delete next;
    }

    string getName() { return symbolName; }
    string getType() { return symbolType; }
    SymbolInfo* getNext() { return next; }
    void setNext(SymbolInfo* nextSymbol) { next = nextSymbol; }
    void setName(string name) { symbolName = name; }
    void setType(string type) { symbolType = type; }

    string getVarType() { return varType; }
    void setVarType(string vt) { varType = vt; }

    bool getisArr() { return isArr; }
    void setisArr(bool arr) { isArr = arr; }

    int getarrSz() { return arrSz; }
    void setarrSz(int sz) { arrSz = sz; }

    bool getIsFunction() { return isFunction; }
    void setIsFunction(bool func) { isFunction = func; }

    bool getIsDefined() { return isDefined; }
    void setIsDefined(bool def) { isDefined = def; }

    string getretType() { return retType; }
    void setretType(string rType) { retType = rType; }


    int getParamCount() const { return paramCount; }
    string getParamType(int i) const {
        if (i >= 0 && i < paramCount && paramTypes != NULL) return paramTypes[i];
        return "";
    }
    string getParamName(int i) const {
        if (i >= 0 && i < paramCount && paramNames != NULL) return paramNames[i];
        return "";
    }

    void addParam(string type, string name) {
        string* newTypes = new string[paramCount + 1];
        string* newNames = new string[paramCount + 1];
        for (int i = 0; i < paramCount; i++) {
            newTypes[i] = paramTypes[i];
            newNames[i] = paramNames[i];
        }
        newTypes[paramCount] = type;
        newNames[paramCount] = name;
        if (paramTypes != NULL) delete[] paramTypes;
        if (paramNames != NULL) delete[] paramNames;
        paramTypes = newTypes;
        paramNames = newNames;
        paramCount++;
    }

    void setParams(const vector<string>& types, const vector<string>& names) {
        if (paramTypes != NULL) delete[] paramTypes;
        if (paramNames != NULL) delete[] paramNames;
        paramCount = types.size();
        if (paramCount > 0) {
            paramTypes = new string[paramCount];
            paramNames = new string[paramCount];
            for (int i = 0; i < paramCount; i++) {
                paramTypes[i] = types[i];
                paramNames[i] = (i < (int)names.size()) ? names[i] : "";
            }
        } else {
            paramTypes = NULL;
            paramNames = NULL;
        }
    }

    void printSymbolInfo(){
        if(symbolType == "FUNCTION"){
            cout << "<" << symbolName << "," << symbolType << "," << retType << "<==(";
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

    void printSymbolInfo(ostream& os) {
        os << "< " << symbolName << " , " << symbolType << " >";
        if (!isFunction) os << " ";
    }
};