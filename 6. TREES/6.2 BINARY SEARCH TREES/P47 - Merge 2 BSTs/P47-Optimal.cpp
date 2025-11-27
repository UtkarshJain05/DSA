// Merge 2 BSTs (Optimal)  -->  TC:O((m+n))  SC:O(m+n).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inorder(Node *root, vector<int> &in)
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
    return;
}

vector<int> merge_bst(Node *root1, Node *root2)
{
    vector<int> ans, in_root1, in_root2;
    inorder(root1, in_root1);
    inorder(root2, in_root2);

    // merging both inorders
    int i = 0, j = 0;
    int m = in_root1.size(), n = in_root2.size();
    while (i < m && j < n)
    {
        if (in_root1[i] <= in_root2[j])
        {
            ans.push_back(in_root1[i]);
            i++;
        }
        else
        {
            ans.push_back(in_root2[j]);
            j++;
        }
    }
    while (i < m)
    {
        ans.push_back(in_root1[i]);
        i++;
    }
    while (j < n)
    {
        ans.push_back(in_root2[j]);
        j++;
    }
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