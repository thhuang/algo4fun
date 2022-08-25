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
    TreeNode* pruneTree(TreeNode* root) {
        function<bool(TreeNode*)> dfs = [&](TreeNode* u) -> bool {
            if (u == nullptr) return false;
            bool l = dfs(u->left);
            bool r = dfs(u->right);
            if (!l) {
                delete u->left;
                u->left = nullptr;
            }
            if (!r) {
                delete u->right;
                u->right = nullptr;
            }
            return l || r || u->val == 1;
        };

        if (!dfs(root)) {
            delete root;
            return nullptr;
        }
        return root;
    }
};

class Solution {
   public:
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) return nullptr;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (root->left || root->right || root->val == 1) return root;
        delete root;
        return nullptr;
    }
};
