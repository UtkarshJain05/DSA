// Recover BST (Optimal)  -->  TC:O(N)  SC:O(1).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void recover_bst(Node *root)
{
    if (!root)
        return;
    Node *first = nullptr;
    Node *mid = nullptr;
    Node *last = nullptr;
    Node *prev_node = nullptr;

    Node *curr = root;
    while (curr)
    {
        if (curr->left == nullptr)
        {
            if (prev_node && curr->data < prev_node->data)
            {
                if (first == nullptr)
                {
                    first = prev_node;
                    mid = curr;
                }
                else
                    last = curr;
            }
            prev_node = curr;
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
                if (curr->data < prev_node->data)
                {
                    if (first == nullptr)
                    {
                        first = prev_node;
                        mid = curr;
                    }
                    else
                        last = curr;
                }
                prev_node = curr;
                curr = curr->right;
            }
        }
    }
    
    // Swapping
    if (last != nullptr)
        swap(first->data, last->data);
    else
        swap(first->data, mid->data);
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