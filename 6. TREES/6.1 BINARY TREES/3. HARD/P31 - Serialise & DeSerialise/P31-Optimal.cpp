// Serialise & DeSerialise.(Optimal) --> TC:O(N)   SC:O(N).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

string Serialise(Node *root)
{
    if (!root)
        return "";
    string s = "";
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if (!curr)
            s.append("#,");
        else
        {
            s.append(to_string(curr->data) + ",");
            q.push(curr->left);
            q.push(curr->right);
        }
    }

    return s;
}

Node *DeSerialise(string data)
{
    if (data.size() == 0)
        return nullptr;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    queue<Node *> q;
    Node *root = new Node(stoi(str));
    q.push(root);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        getline(s, str, ',');
        if (str == "#")
            node->left = nullptr;
        else
        {
            Node *leftnode = new Node(stoi(str));
            node->left = leftnode;
            q.push(leftnode);
        }

        getline(s, str, ',');   
        if (str == "#")
            node->right = nullptr;
        else
        {
            Node *rightnode = new Node(stoi(str));
            node->right = rightnode;
            q.push(rightnode);
        }
    }
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
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    string s = Serialise(root);
    cout << s << "\n";
    Node *ans = DeSerialise(s);
    print(ans);
}