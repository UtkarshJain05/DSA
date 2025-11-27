// BST Iterator (Brute)  -->  TC:O(1)  SC:O(N).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Global vector & pointer.
vector<int> inorder;
int i = 0;

void morris_Traversal(Node *root)
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

int next_val()
{
    if (i == inorder.size())
        return -1;
    return inorder[i++];
}

bool has_next_val()
{
    return (i!=inorder.size());
}

int main()
{

    Node *root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(15);
    root->right->left = new Node(9);
    root->right->right = new Node(20);
    morris_Traversal(root);

    cout << next_val() << "\n";
    cout << next_val() << "\n";
    cout << next_val() << "\n";
    cout << has_next_val() << "\n";
    cout << next_val() << "\n";
    cout << next_val() << "\n";
    cout << has_next_val() << "\n";
}
