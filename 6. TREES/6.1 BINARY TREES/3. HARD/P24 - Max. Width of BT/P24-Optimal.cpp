// Max. Width Of BT--> TC:O(N)    SC:O(N)
// Level Order  Traversal

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int fnc(Node *root)
{
    if (!root)
        return 0;
    int ans = 0;
    queue<pair<Node *, int>> q;
    q.push({root, 1});
    while (!q.empty())
    {
        int n = q.size();
        int minidx = q.front().second;
        int first, last;
        for (int i = 0; i < n; i++)
        {
            Node *node = q.front().first;
            int curr_idx = q.front().second - minidx;
            q.pop();
            if (i == 0)
                first = curr_idx;
            if (i == n - 1)
                last = curr_idx;
            if (node->left)
                q.push({node->left, 2 * curr_idx + 1});
            if (node->right)
                q.push({node->right, 2 * curr_idx + 2});
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->right->right = new Node(4);

    cout << fnc(root);
}