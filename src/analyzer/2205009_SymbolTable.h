#pragma once
#include "2205009_ScopeTable.h"
#include "2205009_SymbolInfo.h"
#include <iostream>

using namespace std;

class SymbolTable {
private:
    ScopeTable* current_scope;
    int bucketSize;

public:
    SymbolTable(int n = 30) {
        bucketSize = n;
        current_scope = new ScopeTable(n, "1");
    }

    ~SymbolTable() {
        ScopeTable* cur = current_scope;
        while (cur != nullptr) {
            ScopeTable* tmp = cur->getParentScope();
            delete cur;
            cur = tmp;
        }
    }

    ScopeTable* getCurrentScope() {
        return current_scope;
    }

    void enterScope() {
        int childId = current_scope->getNextChildId();
        string newId = current_scope->getScopeId() + "." + to_string(childId);
        ScopeTable* new_scope = new ScopeTable(bucketSize, newId);
        new_scope->setParentScope(current_scope);
        current_scope = new_scope;
    }

    void enterScope(int n, string new_id) {
        ScopeTable* new_scope = new ScopeTable(n, new_id);
        new_scope->setParentScope(current_scope);
        current_scope = new_scope;
    }

    void exitScope() {
        if (current_scope->getParentScope() == NULL) {
            return;
        }
        ScopeTable* tmp = current_scope;
        current_scope = current_scope->getParentScope();
        delete tmp;
    }

    bool insert(SymbolInfo *r, int &idx, int &pos, string &scope_id) {
        scope_id = current_scope->getScopeId();
        return current_scope->insert(r, idx, pos);
    }

    bool insert(SymbolInfo *r, int &idx, int &pos) {
        return current_scope->insert(r, idx, pos);
    }

    bool insert(SymbolInfo *r) {
        int idx, pos;
        return current_scope->insert(r, idx, pos);
    }

    bool remove(string name, int &idx, int &pos, string &scope_id) {
        scope_id = current_scope->getScopeId();
        return current_scope->Delete(name, idx, pos);
    }

    bool remove(string name, int &idx, int &pos) {
        return current_scope->Delete(name, idx, pos);
    }

    bool remove(SymbolInfo *r) {
        int idx, pos;
        return current_scope->Delete(r->getName(), idx, pos);
    }

    bool remove(string name) {
        int idx, pos;
        return current_scope->Delete(name, idx, pos);
    }

    SymbolInfo* lookup(string name, int &idx, int &pos, string &scope_id) {
        ScopeTable* tmp = current_scope;
        while (tmp != NULL) {
            SymbolInfo* res = tmp->lookup(name, idx, pos);
            if (res != NULL) {
                scope_id = tmp->getScopeId();
                return res;
            }
            tmp = tmp->getParentScope();
        }
        return NULL;
    }

    SymbolInfo* lookup(string name, int &idx, int &pos) {
        ScopeTable* tmp = current_scope;
        while (tmp != NULL) {
            SymbolInfo* res = tmp->lookup(name, idx, pos);
            if (res != NULL) {
                return res;
            }
            tmp = tmp->getParentScope();
        }
        return NULL;
    }

    SymbolInfo* lookup(SymbolInfo *r) {
        int idx, pos;
        return lookup(r->getName(), idx, pos);
    }

    SymbolInfo* lookup(string name) {
        int idx, pos;
        return lookup(name, idx, pos);
    }

    SymbolInfo* lookupLocal(string name, int &idx, int &pos) {
        if (current_scope != NULL) {
            return current_scope->lookup(name, idx, pos);
        }
        return NULL;
    }

    SymbolInfo* lookupLocal(string name) {
        int idx, pos;
        return lookupLocal(name, idx, pos);
    }

    void printCurrent(ostream& os = cout) {
        if (current_scope != NULL) {
            current_scope->print(os);
        }
    }

    void printAll(ostream& os = cout) {
        ScopeTable* tmp = current_scope;
        while (tmp != NULL) {
            tmp->print(os);
            tmp = tmp->getParentScope();
            if (tmp != NULL) {
                os << "\n";
            }
        }
    }

};