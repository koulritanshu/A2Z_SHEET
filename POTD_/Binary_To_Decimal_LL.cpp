#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *next = NULL;
    int data = 0;
};

class Solution
{
public:
    // Should return decimal equivalent modulo 1000000007 of binary linked list
    long long unsigned int decimalValue(Node *head)
    {
        long long unsigned int ans = 0, M = 1e9 + 7;
        Node *current = head;

        while (current)
        {

            ans = ans * 2 + current->data;
            ans %= M;
            current = current->next;
        }
        return ans;
    }
};