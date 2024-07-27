#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        if(x == 1){
            Node* temp = head;
            head = head->next;
            delete(temp);
            return head;
        }
        int cnt = 1;
        Node* temp = head;
        while(cnt != x){
            temp = temp->next;
            cnt++;
        }
        temp->prev->next = temp->next;
        if(temp->next)
        temp->next->prev = temp->prev;
        delete(temp);
        return head;
    }
};