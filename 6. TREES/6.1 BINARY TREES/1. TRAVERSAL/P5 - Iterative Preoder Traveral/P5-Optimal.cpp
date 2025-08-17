// PreOrder Traversal (Iterative) -->   TC:O(N)  SC:O(N).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> fnc(Node *root)
{
    vector<int> ans;
    if (root == nullptr)
        return ans;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        root = st.top();
        ans.push_back(root->data);
        st.pop();
        if (root->right != nullptr)
            st.push(root->right);
        if (root->left != nullptr)
            st.push(root->left);
    }
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans = fnc(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}
