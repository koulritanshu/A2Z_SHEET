#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countOfAtoms(string f) {
        vector<string> e;
        f = '(' + f + ')';
        for(int i=0;i<f.size();i++){
            if(f[i]=='('){
                e.push_back("(");
            }
            else if(f[i]==')'){
                e.push_back(")");
            }
            else{
                if(f[i]>='A'&&f[i]<='Z'){
                    string curr = "";
                    curr+=f[i];
                    while(i+1<f.size()&&f[i+1]>='a'&&f[i+1]<='z'){
                        curr+=f[i+1];
                        i++;
                    }
                    e.push_back(curr);
                }
                else if(f[i]>='0'&&f[i]<='9'){
                    string curr = "";
                    curr+=f[i];
                    while(i+1<f.size()&&f[i+1]>='0'&&f[i+1]<='9'){
                        curr+=f[i+1];
                        i++;
                    }
                    e.push_back(curr);
                }
            }
        }
        stack<int> st;
        map<string,int> ans;
        string prev;
        // for(int i=0;i<e.size();i++){
        //     cout << e[i] << " ";
        // }
        // cout<<endl;
        map<int,int> indi;
        for(int i=0;i<e.size();i++){
            if(e[i]=="("){
                st.push(i);
            }
            else if(e[i]==")"){
                int to = st.top();
                indi[to] = i;
                st.pop();
            }
        }
        int multi = 1;
        for(int i=0;i<e.size();i++){
            string curr = e[i];
            if(curr=="("){
                int endi = indi[i]; 
                if(endi+1<e.size() && isdigit(e[endi+1][0])){
                    multi *= stoi(e[endi+1]);
                }
            }
            else if(curr==")"){
                if(i+1<e.size() && isdigit(e[i+1][0])){
                    multi = multi / stoi(e[i+1]);
                    i++;
                }
            }
            else if(curr[0]>='A'&&curr[0]<='Z'){
                if(i+1<e.size() && isdigit(e[i+1][0])){
                    string prev = e[i];
                    i++;
                    ans[prev] += (multi*stoi(e[i]));
                }
                else{
                    ans[e[i]] += multi;
                }
            }
        }
        // for(auto &i:ans){
        //     cout << i.first << " " << i.second << endl;
        // }
        string anss = "";
        for(auto &i:ans){
            anss += i.first;
            if(i.second>1){
                anss += to_string(i.second);
            }
        }
        return anss;
    }
};