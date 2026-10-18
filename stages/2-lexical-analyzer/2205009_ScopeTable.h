#pragma once
#include "2205009_SymbolInfo.h"
#include<iostream>


class ScopeTable{
private:
    SymbolInfo** table;
    ScopeTable* parent_scope;
    int n;
    string idx;
    int cld;

public:
    ScopeTable(int n,string id){
        this->n = n;
        cld = 0;
        table = new SymbolInfo*[n];
        for(int i=0; i<n; i++){
            table[i] = NULL;
        }
        parent_scope = NULL;
        idx = id;
        // cout << "\tScopeTable# " << idx << " created" << endl;
    }
    ~ScopeTable(){
        // cout << "\tScopeTable# " << idx << " removed" << endl;
        for(int i=0; i<n; i++){
            delete table[i];
        }
        delete[] table;
    }

    int getCld() { return cld; }
    void incCld() { cld++; }

    ScopeTable* getParentScope(){
        return parent_scope;
    }
    string getId(){
        return idx;
    }
    void setParentScope(ScopeTable* parent){
        parent_scope = parent;
    }

    unsigned int SDBMHash(string str, unsigned int num_buckets){ 
        unsigned int hash = 0; unsigned int len = str.length(); 
        for(unsigned int i = 0; i < len; i++){
            hash = str[i] + (hash << 6) + (hash << 16) - hash;
            // hash = (str[i] + (hash << 6) + (hash << 16) - hash ) % num_buckets; 
        }
        return hash%num_buckets; 
    }

    bool insert(SymbolInfo *r,int &idxx,int &pos){
        unsigned int idx = SDBMHash(r->getName(), n);

        if(table[idx] == NULL){
            table[idx] = r;
            idxx = idx;
            pos = 0;
            return true;
        }

        int cnt = 1;

        SymbolInfo* tmp = table[idx];

        while(tmp->getNext() != NULL){
            if(tmp->getName() == r->getName()){
                return false;
            }
            tmp = tmp->getNext();
            cnt++;
        }
        if(tmp->getName() == r->getName()){
            return false;
        }
        tmp->setNext(r);
        idxx = idx;
        pos = cnt;
        return true;
    }

    SymbolInfo* lookup(string name,int &idxx,int &pos){
        unsigned int idx = SDBMHash(name, n);
        SymbolInfo* tmp = table[idx];
        int cnt = 0;
        while(tmp != NULL){
            if(tmp->getName() == name){
                idxx = idx;
                pos = cnt;
                return tmp;
            }
            tmp = tmp->getNext();
            cnt++;
        }
        return NULL;
    }

    bool Delete(string name, int &idxx,int &pos){
        unsigned int idx = SDBMHash(name, n);
        SymbolInfo* tmp = table[idx];
        SymbolInfo* prev = NULL;
        int cnt = 0;
        while(tmp != NULL){
            if(tmp->getName() == name){
                if(prev == NULL){
                    table[idx] = tmp->getNext();
                }
                else{
                    prev->setNext(tmp->getNext());
                }
                pos = cnt;
                idxx = idx;
                tmp->setNext(NULL);
                cnt++;
                delete tmp;
                return true;

            }
            prev = tmp;
            tmp = tmp->getNext();
        }
        return false;
    }

    void print(ostream &out,int depth){
        // for(int j=0; j<depth; j++) cout << "\t";
        out << "ScopeTable # " << idx << endl;
        for(int i=0; i<n; i++){
            if(table[i] == NULL) continue;
            // for(int j=0; j<depth; j++) out << "\t";
            out << i << " --> ";
            SymbolInfo* tmp = table[i];
            while(tmp != NULL){
                tmp->printSymbolInfo(out);
                tmp = tmp->getNext();
                // out << " ";
            }
            out << endl;
        }
    }

};
