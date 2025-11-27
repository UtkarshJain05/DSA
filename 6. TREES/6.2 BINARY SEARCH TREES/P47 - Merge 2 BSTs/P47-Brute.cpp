// Merge 2 BSTs (Brute)  -->  TC:O((m+n)*log(m+n))  SC:O(m+n).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inorder(Node *root, vector<int> &ans)
{
    if (root == nullptr)
        return;
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
    return;
}

vector<int> merge_bst(Node *root1, Node *root2)
{
    vector<int> ans;
    inorder(root1, ans);
    inorder(root2, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    Node *root1 = new Node(12);
    root1->left = new Node(9);
    root1->left->left = new Node(6);
    root1->left->right = new Node(11);

    Node *root2 = new Node(8);
    root2->left = new Node(5);
    root2->right = new Node(10);
    root2->left->left = new Node(2);

    vector<int> ans = merge_bst(root1, root2);
    for (auto it : ans)
    {
        cout << it << " ";
    }
}