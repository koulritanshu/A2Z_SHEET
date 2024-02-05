#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *sortedInsert(Node *head, int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            newNode->next = newNode;
            return newNode;
        }
        if (data < head->data)
        {
            Node *tmp = head;
            while (tmp->next != head)
            {
                tmp = tmp->next;
            }
            tmp->next = newNode;
            newNode->next = head;
            return newNode;
        }
        if (head->next == head && data > head->data)
        {
            head->next = newNode;
            newNode->next = head;
            return head;
        }
        Node *temp = head;
        Node *next1 = temp->next;
        while (temp->next != head)
        {
            if ((data >= temp->data) && (data <= next1->data))
            {
                temp->next = newNode;
                newNode->next = next1;

                return head;
            }
            else
            {
                if (next1->next == head)
                {
                    next1->next = newNode;
                    newNode->next = head;
                    return head;
                }
                temp = temp->next;
                next1 = next1->next;
            }
        }
    }
};