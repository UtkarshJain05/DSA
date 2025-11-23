// Construct preorder to BST.(Better)   TC:O(NlogN + N)   SC:O(2*N)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node *rec(vector<int> pre, int prestart, int preend, vector<int> in, int instart, int inend, unordered_map<int, int> mp)
{
    if(prestart>preend||instart>inend) return nullptr;
    
    Node*root = new Node(pre[prestart]);

    int inroot = mp[pre[prestart]];
    int numsleft = inroot-instart;

    root->left = rec(pre,prestart+1,prestart+numsleft,in,instart,inroot-1,mp);
    root->right = rec(pre,prestart+numsleft+1,preend,in,inroot+1,inend,mp);

    return root;
}

Node *construct_bst(vector<int> pre)
{
    int n = pre.size();
    if (n == 0)
        return nullptr;
    vector<int> in = pre;
    unordered_map<int, int> mp;
    sort(in.begin(), in.end());
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
            Node *node = q.front();
            q.pop();
            cout << node->data << " ";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        cout << endl;
    }
}

int main()
{
    vector<int> pre = {8, 5, 1, 7, 10, 12};
    Node *root = construct_bst(pre);
    print(root);
}