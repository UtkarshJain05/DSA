// Construct BT From Pre and IN order.(Optimal) --> TC:O(N)   SC:O(2N).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node *rec(vector<int> &pre, int preStart, int PreEnd, vector<int> &in, int inStart, int inEnd, unordered_map<int, int> &mp)
{
    if (preStart > PreEnd || inStart > inEnd)
        return nullptr;

    Node *root = new Node(pre[preStart]);

    int inRoot = mp[pre[preStart]];
    int numsleft = inRoot - inStart;

    root->left = rec(pre, preStart + 1, preStart + numsleft, in, inStart, inRoot - 1, mp);
    root->right = rec(pre, preStart + numsleft + 1, PreEnd, in, inRoot + 1, inEnd, mp);
    return root;
}

Node *buildTree(vector<int> &pre, vector<int> &in)
{
    unordered_map<int, int> mp;
    int n = in.size();
    for (int i = 0; i < n; i++)
    {
        mp[in[i]] = i;
    }

    Node *root = rec(pre, 0, n - 1, in, 0, n - 1, mp);
    return root;
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
            root = q.front();
            q.pop();
            cout << root->data << " ";
            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }
        cout << endl;
    }
}

int main()
{
    vector<int> pre = {10, 20, 40, 50, 30, 60};
    vector<int> in = {40, 20, 50, 10, 60, 30};
    Node *root = buildTree(pre, in);
    print(root);
}