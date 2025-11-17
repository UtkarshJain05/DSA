#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node *findlastright(Node *node)
{
    while (node->right)
    {
        node = node->right;
    }
    return node;
}

Node *del_node(Node *root)
{
    if(!root->left&&!root->right) return nullptr;
    if (!root->left)
        return root->right;
    if (!root->right)
        return root->left;
    Node *rightChild = root->right;
    Node *lastright = findlastright(root->left);
    lastright->right = rightChild;
    return root->left;
}

Node *deletion(Node *root, int key)
{
    if (!root)
        return nullptr;
    if (root->data == key)
        return del_node(root);
    Node *dummy = root;
    while (root)
    {
        if (root->data > key)
        {
            if (root->left && root->left->data == key)
            {
                root->left = del_node(root->left);
                break;
            }
            else
                root = root->left;
        }
        else
        {
            if (root->right && root->right->data == key)
            {
                root->right = del_node(root->right);
                break;
            }
            root = root->right;
        }
    }
    return dummy;
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
    Node *root = new Node(8);
    root->left = new Node(5);
    root->left->left = new Node(2);
    root->left->left->left = new Node(1);
    root->left->left->right = new Node(3);
    root->left->left->right->right = new Node(4);
    root->left->right = new Node(7);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(8);
    root->right = new Node(12);
    root->right->left = new Node(10);
    root->right->right = new Node(13);

    Node *ans = deletion(root, 5);

    print(ans);
}