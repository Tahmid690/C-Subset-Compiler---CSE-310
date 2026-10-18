#pragma once
#include "2205009_SymbolInfo.h"
#include <iostream>
#include <string>

using namespace std;

class ScopeTable {
private:
    SymbolInfo** table;
    ScopeTable* parent_scope;
    int n;
    string scopeId;
    int childCount;

public:
    ScopeTable(int n, string id) {
        this->n = n;
        table = new SymbolInfo*[n];
        for (int i = 0; i < n; i++) {
            table[i] = NULL;
        }
        parent_scope = NULL;
        scopeId = id;
        childCount = 0;
    }

    ~ScopeTable() {
        for (int i = 0; i < n; i++) {
            delete table[i];
        }
        delete[] table;
    }

    ScopeTable* getParentScope() { return parent_scope; }
    string getScopeId() { return scopeId; }
    void setParentScope(ScopeTable* parent) { parent_scope = parent; }

    int getNextChildId() {
        childCount++;
        return childCount;
    }

    unsigned int SDBMHash(string str, unsigned int num_buckets) {
        unsigned int hash = 0;
        unsigned int len = str.length();
        for (unsigned int i = 0; i < len; i++) {
            hash = (str[i] + (hash << 5) - hash) % num_buckets;
        }
        return hash;
    }








    bool insert(SymbolInfo *r) {
        int idxx, pos;
        return insert(r, idxx, pos);
    }

    SymbolInfo* lookup(string name) {
        int idxx, pos;
        return lookup(name, idxx, pos);
    }

    bool Delete(string name) {
        int idxx, pos;
        return Delete(name, idxx, pos);
    }

    bool insert(SymbolInfo *r, int &idxx, int &pos) {

        unsigned int idx = SDBMHash(r->getName(), n);

        if (table[idx] == NULL) {
            table[idx] = r;
            idxx = idx;
            pos = 0;
            return true;
        }

        int cnt = 1;
        SymbolInfo* tmp = table[idx];

        while (tmp->getNext() != NULL) {
            if (tmp->getName() == r->getName()) {
                return false;
            }
            tmp = tmp->getNext();
            cnt++;
        }
        if (tmp->getName() == r->getName()) {
            return false;
        }
        tmp->setNext(r);
        idxx = idx;
        pos = cnt;
        return true;
    }

    SymbolInfo* lookup(string name, int &idxx, int &pos) {
        unsigned int idx = SDBMHash(name, n);
        SymbolInfo* tmp = table[idx];
        int cnt = 0;
        while (tmp != NULL) {
            if (tmp->getName() == name) {
                idxx = idx;
                pos = cnt;
                return tmp;
            }
            tmp = tmp->getNext();
            cnt++;
        }
        return NULL;
    }

    bool Delete(string name, int &idxx, int &pos) {
        unsigned int idx = SDBMHash(name, n);
        SymbolInfo* tmp = table[idx];
        SymbolInfo* prev = NULL;
        int cnt = 0;
        while (tmp != NULL) {
            if (tmp->getName() == name) {
                if (prev == NULL) {
                    table[idx] = tmp->getNext();
                } else {
                    prev->setNext(tmp->getNext());
                }
                pos = cnt;
                idxx = idx;
                tmp->setNext(NULL);
                delete tmp;
                return true;
            }
            prev = tmp;
            tmp = tmp->getNext();
            cnt++;
        }
        return false;
    }

    void print(ostream& os) {
        os << "ScopeTable # " << scopeId << "\n";
        for (int i = 0; i < n; i++) {
            if (table[i] != NULL) {
                os << " " << i << " --> ";
                SymbolInfo* tmp = table[i];
                while (tmp != NULL) {
                    tmp->printSymbolInfo(os);
                    tmp = tmp->getNext();
                }
                os << "\n";
            }
        }
        os << "\n\n";
    }






};

