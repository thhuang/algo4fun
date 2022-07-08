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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> result = {root->val};

        function<void(TreeNode*)> searchLeft = [&](TreeNode* u) -> void {
            while (u && (u->left || u->right)) {
                result.emplace_back(u->val);
                u->left ? u = u->left : u = u->right;
            }
        };

        function<void(TreeNode*)> searchRight = [&](TreeNode* u) -> void {
            int offset = result.size();
            while (u && (u->right || u->left)) {
                result.emplace_back(u->val);
                u->right ? u = u->right : u = u->left;
            }
            reverse(result.begin() + offset, result.end());
        };

        function<void(TreeNode*)> searchLeaves = [&](TreeNode* u) -> void {
            if (u == nullptr) return;
            searchLeaves(u->left);
            if (!u->left && !u->right) {
                result.emplace_back(u->val);
                return;
            }
            searchLeaves(u->right);
        };

        searchLeft(root->left);
        searchLeaves(root->left);
        searchLeaves(root->right);
        searchRight(root->right);

        return result;
    }
};
