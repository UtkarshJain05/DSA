// Insertion In a Binary Search Tree.(Optimal) --> TC:O(logN)   SC:O(1).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node *insertion(Node *root, int val)
{
    if (!root)
        return new Node(val);
    Node *curr = root;
    while (true)
    {
        if (curr->data < val)
        {
            if (curr->right)
                curr = curr->right;
            else
            {
                curr->right = new Node(val);
                break;
            }
        }
        else
        {
            if (curr->left)
                curr = curr->left;
            else
            {
                curr->left = new Node(val);
                break;
            }
        }
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
    Node *root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(7);

    Node *ans = insertion(root, 3);

    print(root);
}