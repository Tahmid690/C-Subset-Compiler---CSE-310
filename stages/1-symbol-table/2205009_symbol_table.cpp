#include<iostream>
#include<string>

using namespace std;






class SymbolTable{
private:
    ScopeTable* current_scope;
    ScopeTable* parent_scope;
public:
    SymbolTable(int n){
        current_scope = new ScopeTable(n);
        parent_scope = NULL;
    }
    ~SymbolTable(){
        delete current_scope;
    }
    void enterScope(int n){
        ScopeTable* new_scope = new ScopeTable(n);
        new_scope->parent_scope = current_scope;
        current_scope = new_scope;
    }
    void exitScope(){
        ScopeTable* tmp = current_scope;
        current_scope = current_scope->parent_scope;
        delete tmp;
    }
    bool insert(SymbolInfo *r){
        returncurrent_scope->insert(r);
    }
    bool remove(string name){
        return current_scope->Delete(name);
    }
    SymbolInfo* lookup(string name){
        ScopeTable* tmp = current_scope;
        while(tmp != NULL){
            SymbolInfo* res = tmp->lookup(name);
            if(res != NULL){
                return res;
            }
            tmp = tmp->parent_scope;
        }
        return NULL;
    }
    void printCurrent(){
        current_scope->print();
    }
    void printAll(){
        ScopeTable* tmp = current_scope;
        while(tmp != NULL){
            tmp->print();
            tmp = tmp->parent_scope;
        }
    }
}

int main(){
    
}