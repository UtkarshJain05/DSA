// kth Smallest Element.  TC:O(n)  SC:O(1).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Inorder = left -> root -> right.
int inorder_morris(Node *root, int k)
{
    if (!root)
        return -1;
    Node *curr = root;
    int cnt = 0;
    int ans = -1;
    while (curr)
    {
        if (curr->left == nullptr)
        {
            cnt++;
            if (cnt == k)
                ans = curr->data;
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
            else // prev->right == curr
            {
                prev->right = nullptr;
                cnt++;
                if (cnt == k)
                    ans = curr->data;
                curr = curr->right;
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

    cout << inorder_morris(root, 10);
}