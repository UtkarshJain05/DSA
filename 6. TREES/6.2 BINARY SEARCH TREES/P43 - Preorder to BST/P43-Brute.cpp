// Construct preorder to BST.(Brute)   TC:O(N^2)   SC:O(1)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node *insert(Node *root, int k)
{
    Node *dummy = root;
    while (true)
    {
        if (root->data > k)
        {
            if (root->left)
                root = root->left;
            else
            {
                root->left = new Node(k);
                break;
            }
        }
        else
        {
            if (root->right)
                root = root->right;
            else
            {
                root->right = new Node(k);
                break;
            }
        }
    }
    return dummy;
}

Node *construct_bst(vector<int> pre)
{
    int n = pre.size();
    if (n == 0)
        return nullptr;
    Node *root = new Node(pre[0]);
    for (int i = 1; i < n; i++)
    {
        root = insert(root, pre[i]);
    }
    return root;
}

void print(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *node = q.front();
            q.pop();
            cout << node->data << " ";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        cout << endl;
    }
}

int main()
{
    vector<int> pre = {8, 5, 1, 7, 10, 12};
    Node *root = construct_bst(pre);
    print(root);
}