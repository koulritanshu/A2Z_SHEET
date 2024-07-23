// Wrong problem link

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char compute(char sign, char curr, char exp){
        if(sign=='|'){
            if(curr=='t'||exp=='t') return 't';
            return 'f';
        }
        else if(sign=='&') {
            if(curr=='t'&&exp=='t') return 't';
            return 'f';
        }
        return 'f';
    }
    void func(stack<char> st){
        while(!st.empty()){
            cout<<st.top()<<" ";st.pop();
        }
        cout<<endl;
    }
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(int i=0;i<expression.size();i++){
            if(expression[i]==')'){
                char val = st.top();
                st.pop();
                char exp = st.top();
                st.pop();
                char curr=val;
                if(exp=='!'){
                    if(curr=='t'){
                        curr='f';
                    }
                    else{
                        curr='t';
                    }
                }
                if(st.empty() || (st.top() != 't' && st.top() != 'f')){
                    st.push(curr);
                } 
                else{
                    exp = st.top();
                    st.pop();
                    char sign = st.top();
                    char result = compute(sign, curr, exp);
                    st.push(result);
                }
            }
            else if(expression[i]=='(' || expression[i]==',') {}
            else if(expression[i]=='!' || expression[i]=='&' || expression[i]=='|'){
                st.push(expression[i]);
            }
            else if(expression[i]=='t'||expression[i]=='f'){
                char curr = expression[i];
                if(st.top() != 't' && st.top() != 'f'){
                    st.push(curr);
                } 
                else{
                    char exp = st.top();
                    st.pop();
                    char sign = st.top();
                    char result = compute(sign, curr, exp);
                    st.push(result);
                }
            }
            // cout<<i<< ". "<<expression[i]<<" --> ";func(st);
        }
        return (st.top()=='t');
    }
};