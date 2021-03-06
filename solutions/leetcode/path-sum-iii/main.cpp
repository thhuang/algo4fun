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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long, int> sum_count;
        ++sum_count[0];

        int result = 0;
        long v = 0;
        function<void(TreeNode*)> dfs = [&](TreeNode* u) -> void {
            if (!u) return;

            v += u->val;
            result += sum_count[v - targetSum];
            ++sum_count[v];

            dfs(u->left);
            dfs(u->right);

            --sum_count[v];
            v -= u->val;
        };

        dfs(root);

        return result;
    }
};
