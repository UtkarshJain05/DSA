// BST Iterator(Optimal)  -->  TC:O(1)  SC:O(H).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Global Stack
stack<Node *> s;

void pushall(Node *node)
{
    while (node)
    {
        s.push(node);
        node = node->left;
    }
    return;
}

void initIterator(Node *root)
{
    if (!root)
        return;
    pushall(root);
}

int next_val()
{
    if (s.empty())
        return -1;
    Node *temp = s.top();
    s.pop();
    if (temp->right)
        pushall(temp->right);
    return temp->data;
}

bool has_next_val()
{
    return !s.empty();
}

int main()
{

    Node *root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(15);
    root->right->left = new Node(9);
    root->right->right = new Node(20);
    initIterator(root);

    cout << next_val() << "\n";
    cout << next_val() << "\n";
    cout << next_val() << "\n";
    cout << has_next_val() << "\n";
    cout << next_val() << "\n";
    cout << next_val() << "\n";
    cout << has_next_val() << "\n";
}
