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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        function<void(TreeNode*, vector<int>&)> dfs =
            [&](TreeNode* u, vector<int>& leaves) -> void {
            if (u->left == nullptr && u->right == nullptr) {
                leaves.push_back(u->val);
                return;
            }
            if (u->left != nullptr) dfs(u->left, leaves);
            if (u->right != nullptr) dfs(u->right, leaves);
        };

        vector<int> leaves1, leaves2;
        dfs(root1, leaves1);
        dfs(root2, leaves2);

        return leaves1 == leaves2;
    }
};
