/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
   public:
    Node* inorderSuccessor(Node* node) {
        if (auto p = node->right; p) {
            while (p->left) p = p->left;
            return p;
        }

        auto p = node;
        while (p->parent && p->parent->right == p) p = p->parent;
        return p->parent;
    }
};
