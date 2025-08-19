// Left View of BT  --> TC:O(N)    SC:O(N)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void rec(Node *root, int level, vector<int> &ans)
{
    if (!root)
        return;
    if (level == ans.size())
        ans.push_back(root->data);
    rec(root->left,level+1,ans);
    rec(root->right,level+1,ans);
}

vector<int> fnc(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    rec(root, 0, ans);
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans = fnc(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}