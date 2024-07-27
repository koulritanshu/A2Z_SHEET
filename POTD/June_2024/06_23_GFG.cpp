#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        int tot = 0;
        vector<int> ans;
        stack<int> st;
        for(int i=0;i<str.size();i++){
            if(str[i]=='('){
                st.push(++tot);
                ans.push_back(tot);
            }
            else if(str[i]==')'){
                ans.push_back(st.top());
                st.pop();
            }
        }
        return ans;
    }
};