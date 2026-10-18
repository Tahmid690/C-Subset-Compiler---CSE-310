#ifndef OPTIMIZER_2205009_H
#define OPTIMIZER_2205009_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

static string trim_space(const string& s){
    int st = s.find_first_not_of(" \t\r\n");
    if(st == string::npos) return "";
    int ed = s.find_last_not_of(" \t\r\n");
    return s.substr(st, ed - st + 1);
}

void replace_label(string& line, const string& olbl, const string& nlbl){
    int pos = 0;
    while((pos = line.find(olbl, pos)) != string::npos){
        bool lok =(pos == 0 ||(!isalnum(line[pos - 1]) && line[pos - 1] != '_'));
        int edPos = pos + olbl.length();
        bool rok =(edPos == line.length() ||(!isalnum(line[edPos]) && line[edPos] != '_'));
        if(lok && rok){
            line.replace(pos, olbl.length(), nlbl);
            pos += nlbl.length();
        }
        else{
            pos += olbl.length();
        }
    }
}

void optimizer(string inFile, string outFile){
    ifstream fin(inFile);
    if(!fin.is_open()) return;

    vector<string> lines;
    string l;
    while(getline(fin, l)){
        lines.push_back(l);
    }
    fin.close();

    bool cng = true;
    while(cng){
        cng = false;

        // Removing redundant labels
        for(int i = 0; i + 1 < lines.size(); i++){
            string t1 = trim_space(lines[i]);
            string t2 = trim_space(lines[i + 1]);

            if(!t1.empty() && t1.back() == ':' && !t2.empty() && t2.back() == ':' ){
                string l1 = t1.substr(0, t1.length() - 1);
                string l2 = t2.substr(0, t2.length() - 1);

                for(int k = 0; k < lines.size(); k++){
                    if(k != i + 1){
                        replace_label(lines[k], l2, l1);
                    }
                }
                lines.erase(lines.begin() + i + 1);
                cng = true;
                break;
            }
        }
        if(cng) continue;

        // others
        for(int i = 0; i < lines.size(); i++){
            string t1 = trim_space(lines[i]);
            if(t1.empty() || t1[0] == ';' || t1.back() == ':') continue;

            int j = i + 1;
            while(j < lines.size()){
                string tj = trim_space(lines[j]);
                if(!tj.empty() && tj[0] != ';') break;
                j++;
            }

            string t2 =(j < lines.size()) ? trim_space(lines[j]) : "";

            stringstream ss1(t1);
            string op1, args1;
            ss1 >> op1;
            getline(ss1, args1);
            op1 = trim_space(op1);
            args1 = trim_space(args1);

            string a1_op1, a1_op2;
            int com1 = args1.find(',');
            if(com1 != string::npos){
                a1_op1 = trim_space(args1.substr(0, com1));
                a1_op2 = trim_space(args1.substr(com1 + 1));
            }
            else{
                a1_op1 = args1;
            }

            //Removing redundant operations
            if((op1 == "ADD" || op1 == "SUB") && a1_op2 == "0"){
                lines.erase(lines.begin() + i);
                cng = true;
                break;
            }
            if((op1 == "MUL" || op1 == "IMUL") && a1_op2 == "1"){
                lines.erase(lines.begin() + i);
                cng = true;
                break;
            }

            if(j < lines.size() && !t2.empty() && t2.back() != ':'){
                stringstream ss2(t2);
                string op2, args2;
                ss2 >> op2;
                getline(ss2, args2);
                op2 = trim_space(op2);
                args2 = trim_space(args2);

                string a2_op1, a2_op2;
                int com2 = args2.find(',');
                if(com2 != string::npos){
                    a2_op1 = trim_space(args2.substr(0, com2));
                    a2_op2 = trim_space(args2.substr(com2 + 1));
                } else{
                    a2_op1 = args2;
                }

                //Removing redundant MOV instruction
                if(op1 == "MOV" && op2 == "MOV" && !a1_op1.empty() && !a1_op2.empty()){
                    if(a1_op1 == a2_op2 && a1_op2 == a2_op1){
                        lines.erase(lines.begin() + j);
                        cng = true;
                        break;
                    }
                }

                //Removing redundant consecutive push and pop
                if(op1 == "PUSH" && op2 == "POP" && a1_op1 == a2_op1 && !a1_op1.empty()){
                    lines.erase(lines.begin() + j);
                    lines.erase(lines.begin() + i);
                    cng = true;
                    break;
                }
            }
        }
    }

    ofstream fout(outFile);
    if(!fout.is_open()) return;
    for(const string& lstr : lines){
        fout << lstr << "\n";
    }
    fout.close();
}

#endif 
