#pragma once
#include "2205009_ScopeTable.h"
#include "2205009_SymbolInfo.h"
#include<iostream>

class SymbolTable{
private:
    ScopeTable* current_scope;
    int n;
    
public:
    SymbolTable(int n){
        this->n = n;
        current_scope = new ScopeTable(n, "1");
    }
    ~SymbolTable(){

        ScopeTable* cur = current_scope;
        while (cur != nullptr) {
            ScopeTable* tmp = cur->getParentScope();
            delete cur;
            cur = tmp;
        }
    }
    ScopeTable* getCurrentScope(){
        return current_scope;
    }

    void enterScope(){
        current_scope->incCld();
        string newId = current_scope->getId() + "." + to_string(current_scope->getCld());
        ScopeTable* new_scope = new ScopeTable(n, newId);
        new_scope->setParentScope(current_scope);
        current_scope = new_scope;
        // logout << "\tScopeTable# " << newId << " created" << endl;
    }
    void exitScope(){
        if(current_scope->getParentScope() == NULL){
            return;
        }
        ScopeTable* tmp = current_scope;
        current_scope = current_scope->getParentScope();
        delete tmp;
    }
    bool insert(SymbolInfo *r,int &idx,int &pos,string &scope_id){
        scope_id = current_scope->getId();
        return current_scope->insert(r, idx, pos);
    }
    bool remove(string name, int& idx, int& pos, string& scope_id){
        scope_id = current_scope->getId();
        return current_scope->Delete(name, idx, pos);
    }
    SymbolInfo* lookup(string name, int& idx, int& pos,string &scope_id){
        ScopeTable* tmp = current_scope;
        while(tmp != NULL){
            SymbolInfo* res = tmp->lookup(name,idx,pos);
            if(res != NULL){
                scope_id = tmp->getId();
                return res;
            }
            tmp = tmp->getParentScope();
        }
        return NULL;
    }
    void printCurrent(ostream &out){
        current_scope->print(out,1);
    }
    void printAll(ostream &out){
        ScopeTable* tmp = current_scope;
        int d = 0;
        while(tmp != NULL){
            tmp->print(out,++d);
            tmp = tmp->getParentScope();
        }
    }
};