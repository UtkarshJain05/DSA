// kth Largest Element.  TC:O(n)  SC:O(1).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int inorder_morris(Node *root, int k)
{
    if (!root || k <= 0)
        return -1;
    int cnt = 0;
    int ans = -1;
    Node *curr = root;
    while (curr)
    {
        if (curr->right == nullptr)
        {
            cnt++;
            if (cnt == k)
                ans = curr->data;
            curr = curr->left;
        }
        else
        {
            Node *prev = curr->right;
            while (prev->left && prev->left != curr)
            {
                prev = prev->left;
            }
            if (!prev->left)
            {
                prev->left = curr;
                curr = curr->right;
            }
            else
            {
                prev->left = nullptr;
                cnt++;
                if (cnt == k)
                    ans = curr->data;
                curr = curr->left;
            }
        }
    }
    return ans;
}

int main()
{
    Node *root = new Node(8);
    root->left = new Node(5);
    root->left->left = new Node(2);
    root->left->left->left = new Node(1);
    root->left->left->right = new Node(3);
    root->left->left->right->right = new Node(4);
    root->left->right = new Node(7);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(8);
    root->right = new Node(12);

    cout << inorder_morris(root, 5);
}