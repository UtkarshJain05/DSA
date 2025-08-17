// Preorder, Inorder & Postorder --> TC:O(3N)   SC:O(4N).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<vector<int>> fnc(Node *root)
{
    vector<vector<int>> ans;
    vector<int> Preorder;
    vector<int> Inorder;
    vector<int> Postorder;
    stack<pair<Node *, int>> st;
    if (root == nullptr)
        return ans;
    st.push({root, 1});

    while (!st.empty())
    {
        pair<Node *, int> node = st.top();
        st.pop();

        if (node.second == 1)
        {
            Preorder.push_back(node.first->data);
            node.second++;
            st.push(node);

            if (node.first->left != nullptr)
            {
                st.push({node.first->left, 1});
            }
        }
        else if (node.second == 2)
        {

            Inorder.push_back(node.first->data);
            node.second++;
            st.push(node);
            if (node.first->right != nullptr)
            {
                st.push({node.first->right, 1});
            }
        }
        else
        {
            Postorder.push_back(node.first->data);
        }
    }
    
    ans.push_back(Preorder);
    ans.push_back(Inorder);
    ans.push_back(Postorder);
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

    vector<vector<int>> ans = fnc(root);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
