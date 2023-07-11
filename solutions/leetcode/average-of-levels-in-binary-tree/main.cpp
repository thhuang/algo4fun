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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        vector<int> amount;

        function<void(TreeNode*, int)> dfs = [&](TreeNode* u, int lv) -> void {
            if (!u) return;

            if (result.size() == lv) {
                result.push_back(0);
                amount.push_back(0);
            }

            result[lv] += u->val;
            ++amount[lv];

            dfs(u->left, lv + 1);
            dfs(u->right, lv + 1);
        };

        dfs(root, 0);

        for (int i = 0; i < result.size(); ++i) result[i] /= amount[i];

        return result;
    }
};
