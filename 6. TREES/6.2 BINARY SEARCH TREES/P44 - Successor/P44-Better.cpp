// Successor in BST. (Better)  -->  TC:O(N)  SC:O(1).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Approach.
// S1 -> Inorder Traversal
// s2 -> as we found k flag (false->true)
// s3 -> then if(flag==true && curr > k) will work to get next value of k.
// s4 -> ans = k+1 && flag = false;

int successor(Node *root, int k)
{
    // Morris Traversal
    if (!root)
        return -1;
    int ans = -1;
    Node *curr = root;
    bool flag = false;
    while (curr)
    {
        if (curr->left == nullptr)
        {
            if (flag == true && curr->data > k)
            {
                ans = curr->data;
                flag = false;
            }
            if (curr->data == k)
                flag = true;
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
                if (flag == true && curr->data > k)
                {
                    ans = curr->data;
                    flag = false;
                }
                if (curr->data == k)
                    flag = true;
                curr = curr->right;
            }
        }
    }
    return ans;
}

int main()
{
    Node *root = new Node(9);
    root->left = new Node(5);
    root->left->left = new Node(2);
    root->left->left->left = new Node(1);
    root->left->left->right = new Node(3);
    root->left->left->right->right = new Node(4);
    root->left->right = new Node(7);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(8);
    root->right = new Node(12);

    cout << successor(root, 5);
}