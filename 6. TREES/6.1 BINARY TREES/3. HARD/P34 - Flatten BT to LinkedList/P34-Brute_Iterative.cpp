// BT to LinkedList (Iterative).(Brute) --> TC:O(N)   SC:O(N).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void to_Linkedlist(Node *&root)
{
    if (!root)
        return;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *curr = st.top();
        st.pop();
        if (curr->right)
            st.push(curr->right);
        if (curr->left)
            st.push(curr->left);
        if (!st.empty())
        {
            curr->right = st.top();
            curr->left = nullptr;
        }
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(8);

    to_Linkedlist(root);
    Node *curr = root;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->right;
    }
}