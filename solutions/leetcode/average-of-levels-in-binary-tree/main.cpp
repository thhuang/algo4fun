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
        vector<double> avgs;
        vector<int> counts;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* u, int lv) -> void {
            if (lv == avgs.size()) avgs.push_back({}), counts.push_back({});
            avgs[lv] += u->val, ++counts[lv];
            if (u->left) dfs(u->left, lv + 1);
            if (u->right) dfs(u->right, lv + 1);
        };
        dfs(root, 0);
        for (int i = 0; i < avgs.size(); ++i) avgs[i] /= counts[i];
        return avgs;
    }
};
