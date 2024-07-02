#include <bits/stdc++.h>
using namespace std;

struct Node{
    string data;
    Node*next;
};

class Solution {
  public:
    bool check(string &x){
        int i=0,j=x.size()-1;
        while(i<j){
            if(x[i]!=x[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    bool compute(Node* head) {
        string x = "";
        while(head){
            x += head->data;
            head=head->next;
        }
        return check(x);
    }
};
