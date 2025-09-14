// Morris Traversal (Inorder).(Optimal) --> TC:O(N)   SC:O(1).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> morris(Node *&root)
{
    vector<int> inorder;
    if (!root)
        return inorder;
    Node *curr = root;
    while (curr != nullptr)
    {
        if (curr->left == nullptr)
        {
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            Node *prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == nullptr)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = nullptr;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return inorder;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->left->right->right = new Node(6);
    vector<int> ans = morris(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}