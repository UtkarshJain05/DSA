// Check Identical Trees --> TC:O(N)  SC:O(N)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool fnc(Node *p, Node *q)
{
    if (p == nullptr || q == nullptr)
        return (p == q);
    return (p->data == q->data) && fnc(p->left, q->left) && fnc(p->right, q->right);
}

int main()
{
    // Tree 1
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(4);
    root1->left->left = new Node(5);

    // Tree 2
    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(4);
    root2->left->left = new Node(5);

    int ans = fnc(root1, root2);
    if (ans == 1)
        cout << "Identical.";
    else
        cout << "Not Identical.";
}