// Recover BST (Brute)  -->  TC:O(2N + NlogN)  SC:O(N).

/* Algo:
S1 -> Store Inorder
S2 -> Sort Inorder
S3 -> Correction - Inorder elements rewriting in the tree.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void morris(Node *root, vector<int> &in)
{
    if (!root)
        return;
    Node *curr = root;
    while (curr)
    {
        if (curr->left == nullptr)
        {
            in.push_back(curr->data);
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
                in.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
}

void correct_bst(Node *root, vector<int> &in)
{
    if (!root)
        return;
    int i = 0;
    Node *curr = root;
    while (curr)
    {
        if (curr->left == nullptr)
        {
            curr->data = in[i++];
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
                curr->data = in[i++];
                curr = curr->right;
            }
        }
    }
}

void recover_bst(Node *root)
{
    if (!root)
        return;
    vector<int> in;
    // Vector Filling.
    morris(root, in);

    // Sorted Vector.
    sort(in.begin(), in.end());

    // Finally Correct the BST
    correct_bst(root, in);
    return;
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
            Node *curr = q.front();
            cout << curr->data << " ";
            q.pop();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        cout << endl;
    }
    return;
}

int main()
{
    Node *root = new Node(3);
    root->left = new Node(1);
    root->right = new Node(4);
    root->right->left = new Node(2);

    print(root);

    recover_bst(root);
    cout << endl;
    print(root);
}