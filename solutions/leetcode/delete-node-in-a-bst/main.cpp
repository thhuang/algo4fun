/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    TreeNode* deleteLeftMost(TreeNode* node) {
        if (!node->left) return node->right;
        node->left = deleteLeftMost(node->left);
        return node;
    }

    TreeNode* deleteRightMost(TreeNode* node) {
        if (!node->right) return node->left;
        node->right = deleteRightMost(node->right);
        return node;
    }

   public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (root->val != key) {
            root->left = deleteNode(root->left, key);
            root->right = deleteNode(root->right, key);
            return root;
        }
        if (root->left == nullptr && root->right == nullptr) return nullptr;
        if (root->right) {
            auto p = root->right;
            while (p->left) p = p->left;
            root->val = p->val;
            root->right = deleteLeftMost(root->right);
        } else {  // root->left
            auto p = root->left;
            while (p->right) p = p->right;
            root->val = p->val;
            root->left = deleteRightMost(root->left);
        }
        return root;
    }
};

class Solution {
   public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (root->val != key) {
            root->left = deleteNode(root->left, key);
            root->right = deleteNode(root->right, key);
            return root;
        }
        if (!root->left && !root->right) return nullptr;
        if (root->left) {
            auto p = root->left;
            while (p->right) p = p->right;
            swap(root->val, p->val);
            root->left = deleteNode(root->left, key);
        } else {  // root->right
            auto p = root->right;
            while (p->left) p = p->left;
            swap(root->val, p->val);
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};

class Solution {
   public:
    TreeNode* largestNode(TreeNode* root) {
        if (root->right == nullptr) return root;
        return largestNode(root->right);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;

        if (root->val != key) {
            if (key < root->val) {
                root->left = deleteNode(root->left, key);
            } else {
                root->right = deleteNode(root->right, key);
            }
            return root;
        }

        if (root->left == nullptr) return root->right;
        if (root->right == nullptr) return root->left;

        auto largest = largestNode(root->left);
        root->val = largest->val;
        root->left = deleteNode(root->left, largest->val);

        return root;
    }
};
