// Largest BST. (Brute)  TC:O(N^2)  SC:O(1).

#include <bits/stdc++.h>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node *left;
    Node *right;
    
    Node(int x) {
        data = x;
        left = nullptr;
      	right = nullptr;
    }
};

// Funtion to validate bst
bool isValidBst(Node *root, int minValue, int maxValue) {
    if (!root)
        return true;
    if (root->data >= maxValue || root->data <= minValue)
        return false;
    return isValidBst(root->left, minValue, root->data) && 
           isValidBst(root->right, root->data, maxValue);
}

// Funtion to calculate size of subtree
int size(Node *root) {
    if (!root)
        return 0;
    return 1 + size(root->left) + size(root->right);
}

// Finds the size of the largest BST
int largestBst(Node *root) {
    if (!root)
        return 0;
    
    // Check Subtree is valid or not
    if (isValidBst(root, INT_MIN, INT_MAX)) 
        return size(root);
  
    // Recursively call for left and right child
    return max(largestBst(root->left), 
               largestBst(root->right));
}

int main() {

    Node *root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    cout << largestBst(root) << endl;
    return 0;
}