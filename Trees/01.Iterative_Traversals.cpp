#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode()
    {
        left = right = NULL;
        val = 0;
    }
};

void Iterative_Inorder(TreeNode *root)
{
    if (!root)
        return;
    stack<TreeNode *> st;
    vector<int> ino;
    while (true)
    {
        if (root)
        {
            st.push(root);
            root = root->left;
        }
        else if (!st.empty())
        {
            ino.push_back(st.top()->val);
            TreeNode *top = st.top();
            st.pop();
            if (top->right)
            {
                root = top->right;
            }
        }
        else
        {
            break;
        }
    }
    for (auto i : ino)
    {
        cout << i << " ";
    }
    cout << endl;
}

void preOrder(TreeNode *root)
{
    stack<TreeNode *> st;
    vector<int> pre;
    while (true)
    {
        if (root)
        {
            pre.push_back(root->val);
            st.push(root);
            root = root->left;
        }
        else if (!st.empty())
        {
            TreeNode *top = st.top();
            st.pop();
            if (top->right)
            {
                root = top->right;
            }
        }
        else
        {
            break;
        }
    }
    for (auto i : pre)
    {
        cout << i << " ";
    }
    cout << endl;
}

void postOrder(TreeNode *root)
{
    stack<TreeNode *> st;
    stack<TreeNode *> st2;
    vector<int> post;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *tp = st.top();
        st.pop();
        post.push_back(tp->val);
        if (tp->left)
        {
            st.push(tp->left);
        }
        if (tp->right)
        {
            st.push(tp->right);
        }
    }
    for (int i = post.size() - 1; i >= 0; i--)
    {
        cout << post[i] << " ";
    }
    cout << endl;
}

void allThree(TreeNode *root)
{
    vector<int> pre;
    vector<int> in;
    vector<int> post;
    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});
    while (!st.empty())
    {
        pair<TreeNode *, int> p = st.top();
        st.pop();
        if (p.second == 1)
        {
            pre.push_back(p.first->val);
            st.push({p.first, 2});
            if (p.first->left)
            {
                st.push({p.first->left, 1});
            }
        }
        else if (p.second == 2)
        {
            in.push_back(p.first->val);
            st.push({p.first, 3});
            if (p.first->right)
            {
                st.push({p.first->right, 1});
            }
        }
        else
        {
            post.push_back(p.first->val);
        }
    }
    for (auto i : in)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : pre)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : post)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    TreeNode *root = new TreeNode();
    root->val = 10;
    TreeNode *node = new TreeNode();
    node->val = 5;
    root->left = node;
    TreeNode *node2 = new TreeNode();
    node2->val = 20;
    root->right = node2;
    root->left->right = new TreeNode();
    root->left->right->val = 7;
    cout << endl;
    Iterative_Inorder(root);
    cout << endl;
    preOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    allThree(root);
}