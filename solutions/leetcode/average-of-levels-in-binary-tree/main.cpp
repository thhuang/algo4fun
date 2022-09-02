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
        vector<double> avg;
        vector<int> cnt;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* u, int lv) -> void {
            if (!u) return;
            if (avg.size() == lv) {
                avg.push_back({});
                cnt.push_back({});
            }
            avg[lv] += u->val;
            ++cnt[lv];
            dfs(u->left, lv + 1);
            dfs(u->right, lv + 1);
        };
        dfs(root, 0);
        for (int i = 0; i < avg.size(); ++i) avg[i] /= cnt[i];
        return avg;
    }
};
