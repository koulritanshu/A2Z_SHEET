#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node*next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *removeAllDuplicates(struct Node *head)
    {
        Node *temp = new Node(-1);
        temp->next = head;
        Node *ans = temp->next;
        Node *dummy = temp;
        while (ans)
        {
            bool inside = false;
            while (ans->next && ans->next->data == ans->data)
            {
                Node *tempp = ans;
                ans = ans->next;
                delete (tempp);
                inside = true;
            }
            if (inside)
            {
                Node *tempp = ans;
                ans = ans->next;
                delete (tempp);
                continue;
            }
            dummy->next = ans;
            dummy = dummy->next;
            ans = ans->next;
        }
        dummy->next = NULL;
        return temp->next;
    }
};