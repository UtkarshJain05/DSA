// Successor in BST. (Brute)  -->  TC:O(N+logN)  SC:O(N).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> fnc(Node *root)
{
    vector<int> inorder;
    if (!root)
        return inorder;
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
                // create thread
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                // remove thread
                prev->right = nullptr;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return inorder;
}

int search(vector<int> &in, int k)
{
    // binary search
    int n = in.size();
    int low = 0, high = n - 1;
    int ans = INT_MIN;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (in[mid] < k)
            low = mid + 1;
        else if (in[mid] > k)
            high = mid - 1;
        else
        {
            ans = mid;
            break;
        }
    }
    return ans;
}

int successor(Node *root, int k)
{
    if (!root)
        return -1;
    vector<int> inorder = fnc(root);
    int n = inorder.size();
    if (inorder[n - 1] < k)
        return -1;
    int idx = search(inorder, k);
    return inorder[idx + 1];
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