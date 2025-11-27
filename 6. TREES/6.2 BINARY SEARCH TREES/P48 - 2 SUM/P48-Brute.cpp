// 2 Sum of BST. (Brute)  -->  TC:O(N)  SC:O(N).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void morris(Node *root, vector<int> &inorder)
{
    if (!root)
        return;
    Node *curr = root;
    while (curr)
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
    return;
}

bool two_sum(Node *root, int k)
{
    if (!root)
        return false;
    vector<int> in;
    morris(root, in);

    int i = 0, j = in.size() - 1;
    while (i < j)
    {
        int sum = in[i] + in[j];
        if (sum == k)
            return true;
        else if (sum > k)
            j--;
        else
            i++;
    }
    return false;
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

    (two_sum(root, 10) == 1) ? cout << "Found!." : cout << "Not Found!";
}