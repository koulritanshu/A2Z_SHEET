#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x){
        val = x;
        next = nullptr;
    }
};


class Solution
{
public:
    int carry = 0;
    void func(ListNode *head)
    {
        if (head->next)
            func(head->next);
        int dou = head->val * 2 + carry;
        if (dou >= 10)
        {
            head->val = dou % 10;
            carry = dou / 10;
        }
        else
        {
            head->val = dou;
            carry = 0;
        }
    }
    ListNode *doubleIt(ListNode *head)
    {
        func(head);
        if (carry)
        {
            ListNode *newNode = new ListNode(1);
            newNode->next = head;
            return newNode;
        }
        return head;
    }
};