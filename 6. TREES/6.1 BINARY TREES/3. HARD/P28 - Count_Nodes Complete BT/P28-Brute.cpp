// Count Nodes of Complete BT.(Brute) --> TC:O(N)   SC:O(N).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void count_nodes(Node *root, int &cnt)
{
    if (!root)
        return;
    cnt++;
    count_nodes(root->left,cnt);
    count_nodes(root->left,cnt);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int cnt = 0;
    count_nodes(root, cnt);
    cout << cnt;
}