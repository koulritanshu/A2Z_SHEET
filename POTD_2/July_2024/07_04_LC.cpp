#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode*next;
    ListNode(int x){
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode*newHead = new ListNode(-1);
        ListNode*dummy = newHead;
        ListNode*iterator = head;
        while(iterator->next){
            if(iterator->val==0){
                dummy->next=iterator;
                dummy=dummy->next;
            }
            else{
                dummy->val=dummy->val+iterator->val;
            }
            iterator=iterator->next;
        }
        dummy->next=NULL;
        head = newHead->next;
        delete(newHead);
        return head;
    }
};