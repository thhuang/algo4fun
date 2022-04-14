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
   public:
    TreeNode* searchBST(TreeNode* root, int val) {
        auto p = root;
        while (p) {
            if (val == p->val) {
                break;
            } else if (val > p->val) {
                p = p->right;
            } else {
                p = p->left;
            }
        }
        return p;
    }
};

class Solution {
   public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) return nullptr;
        if (val == root->val) return root;
        return val < root->val ? searchBST(root->left, val)
                               : searchBST(root->right, val);
    }
};
