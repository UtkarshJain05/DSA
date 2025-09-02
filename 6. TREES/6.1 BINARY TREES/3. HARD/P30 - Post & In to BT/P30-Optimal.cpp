// Construct BT From Post and IN order.(Optimal) --> TC:O(N)   SC:O(2N).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node *rec(vector<int> &post, int postStart, int postEnd, vector<int> &in, int inStart, int inEnd, unordered_map<int, int> &mp)
{
    if (postStart > postEnd || inStart > inEnd)
        return nullptr;

    Node *root = new Node(post[postEnd]);

    int inRoot = mp[post[postEnd]];
    int numsleft = inRoot - inStart;

    root->left = rec(post, postStart, postStart + numsleft - 1, in, inStart, inRoot - 1, mp);
    root->right = rec(post, postStart + numsleft, postEnd - 1, in, inRoot + 1, inEnd, mp);
    return root;
}

Node *buildTree(vector<int> &post, vector<int> &in)
{
    unordered_map<int, int> mp;
    int n = in.size();
    for (int i = 0; i < n; i++)
    {
        mp[in[i]] = i;
    }

    Node *root = rec(post, 0, n - 1, in, 0, n - 1, mp);
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
    vector<int> post = {40, 50, 20, 60, 30, 10};
    vector<int> in = {40, 20, 50, 10, 60, 30};
    Node *root = buildTree(post, in);
    print(root);
}