// Root to Node Path  --> TC:O(N)    SC:O(N)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool rec(Node *root, int x, vector<int> &ans)
{
    if (!root)
        return false;

    ans.push_back(root->data);
    if (root->data == x)
        return true;

    if (rec(root->left, x, ans) || rec(root->right, x, ans))
        return true;
    else
    {
        ans.pop_back();
        return false;
    }
}

vector<int> fnc(Node *root, int x)
{
    vector<int> ans;
    if (!root)
        return ans;
    rec(root, x, ans);
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
    root->left->right->right = new Node(7);

    vector<int> ans = fnc(root, 7);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}