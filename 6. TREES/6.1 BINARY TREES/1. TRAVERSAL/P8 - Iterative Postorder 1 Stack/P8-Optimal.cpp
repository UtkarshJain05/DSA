// PostOrder Traversal {1 Stack Iterative} --> TC:O(2N)  SC:O(N)

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
    stack<Node *> s;
    Node *curr = root;
    while (curr != nullptr || !s.empty())
    {
        if (curr != nullptr)
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            Node *temp = s.top()->right;
            if (temp == nullptr)
            {
                temp = s.top();
                ans.push_back(temp->data);
                s.pop();
                while (!s.empty() && temp == s.top()->right)
                {
                    temp = s.top();
                    ans.push_back(temp->data);
                    s.pop();
                }
            }
            else
                curr = temp;
        }
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
