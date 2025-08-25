// Child Sum Property of BT. --> TC:O(N)  SC:O(N)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void fnc(Node *root)
{
    if (!root)
        return;

    int child = 0;
    if (root->left)
        child += root->left->data;
    if (root->right)
        child += root->right->data;

    if (child < root->data)
    {
        if (root->left)
            root->left->data = root->data;
        if (root->right)
            root->right->data = root->data;
    }

    fnc(root->left);
    fnc(root->right);

    int total = 0;
    if (root->left)
        total += root->left->data;
    if (root->right)
        total += root->right->data;
    if (root->left or root->right)
        root->data = total;
}

void printtree(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            root = q.front();
            cout << root->data << " ";
            q.pop();
            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }
        cout << endl;
    }
}

int main()
{
    Node *root = new Node(40);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(2);
    root->left->right = new Node(5);
    root->right->left = new Node(30);
    root->right->right = new Node(40);

    fnc(root);
    printtree(root);
}