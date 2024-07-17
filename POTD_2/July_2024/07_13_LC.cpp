#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        map<int,pair<int,char>> mp;
        for(int i=0;i<positions.size();i++){
            mp[positions[i]] = {healths[i],directions[i]};
        }
        map<int,int> mpp;
        for(int i=0;i<positions.size();i++){
            mpp[positions[i]] = i;
        }
        sort(positions.begin(),positions.end());
        stack<int> st;
        vector<int> ans;
        for(int i=0;i<positions.size();i++){
            int health = mp[positions[i]].first;
            char direction = mp[positions[i]].second;
            if(direction=='R'){
                st.push(positions[i]);
            }
            else{
                if(st.empty()){
                    ans.push_back(positions[i]);
                }
                else{
                    while(!st.empty() && health!=-99){
                        // cout << st.top() << endl;
                        int prev_score = mp[st.top()].first;
                        if(prev_score > health){
                            mp[st.top()].first-=1;
                            healths[mpp[st.top()]]-=1;
                            break;
                        }
                        else if(prev_score < health){
                            health--;
                            healths[mpp[positions[i]]]--;
                            mp[positions[i]].first-=1;
                            st.pop();
                        }
                        else{
                            st.pop();
                            health = -99;
                            break;
                        }
                    }
                    if(st.empty() && health!=-99){
                        ans.push_back(positions[i]);
                    }
                }
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        // for(int i=0;i<healths.size();i++){
        //     cout<<healths[i]<<" ";
        // }
        // cout<<endl;
        for(int i=0;i<ans.size();i++){
            ans[i] = mpp[ans[i]];
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            ans[i] = healths[ans[i]];
        }
        // for(int i=0;i<ans.size();i++){
        //     cout << ans[i] << ' ';
        // }
        // cout << endl;
        return ans;
    }
};