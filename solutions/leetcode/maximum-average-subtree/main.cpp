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
    double maximumAverageSubtree(TreeNode* root) {
        double result = 0;
        function<pair<int, int>(TreeNode*)> dfs =
            [&](TreeNode* u) -> pair<int, int> {
            if (u == nullptr) return {0, 0};
            int cnt = 1;
            int sum = u->val;

            auto l = dfs(u->left);
            cnt += l.first;
            sum += l.second;

            auto r = dfs(u->right);
            cnt += r.first;
            sum += r.second;

            result = max(result, (double)sum / cnt);

            return {cnt, sum};
        };
        dfs(root);
        return result;
    }
};
