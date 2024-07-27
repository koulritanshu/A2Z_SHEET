#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        vector<int> pair(s.size());
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                int j = st.top();
                st.pop();
                pair[i]=j;
                pair[j]=i;
            }
        }
        string ans = "";
        int j=1;
        for(int i=0;i<s.size()&&i>=0;i+=j){
            if(s[i]=='('||s[i]==')'){
                i=pair[i];
                j=-j;
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};