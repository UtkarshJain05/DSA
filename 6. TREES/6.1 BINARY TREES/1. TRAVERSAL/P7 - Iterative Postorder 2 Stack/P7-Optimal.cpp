// PostOrder Traversal {2 Stack Iterative} --> TC:O(N)  SC:O(2N)

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
    vector<int> ans;
    if (root == nullptr)
        return ans;
    stack<Node *> s1, s2;
    s1.push(root);
    while (!s1.empty())
    {
        root = s1.top();
        s2.push(root);
        s1.pop();
        if (root->left != nullptr)
            s1.push(root->left);
        if (root->right)
            s1.push(root->right);
    }

    while (!s2.empty())
    {
        ans.push_back(s2.top()->data);
        s2.pop();
    }
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans = fnc(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}