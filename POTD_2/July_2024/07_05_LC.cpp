#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode*next;
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int st = -1, ed = -1;
        ListNode*temp = head->next;
        ListNode*pre = head;
        vector<int> ans(2,0);
        int mini_diff = INT_MAX;
        int cnt = 2;
        while(temp->next){
            if(temp->val>pre->val && temp->val>temp->next->val){
                if(st==-1){st = cnt;}
                else if(ed==-1){
                    ed = cnt;
                    mini_diff=min(mini_diff,ed-st);
                }
                else{
                    mini_diff=min(mini_diff,cnt-ed);
                    ed=cnt;
                }
            }
            else if(temp->val<pre->val && temp->val<temp->next->val){
                if(st==-1){st = cnt;}
                else if(ed==-1){
                    ed = cnt;
                    mini_diff=min(mini_diff,ed-st);
                }
                else{
                    mini_diff=min(mini_diff,cnt-ed);
                    ed=cnt;
                }
            }
            pre = temp;
            temp = temp->next;
            cnt++;
        }
        if(ed==-1){
            return {-1,-1};
        }
        else{
            ans[1] = ed-st;
            ans[0] = mini_diff;
            return ans;
        }
    }
};