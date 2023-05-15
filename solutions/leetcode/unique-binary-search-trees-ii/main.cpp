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
    vector<TreeNode*> generateTrees(int n) {
        function<vector<TreeNode*>(int, int)> dfs =
            [&](int l, int r) -> vector<TreeNode*> {
            if (r < l) return {nullptr};

            vector<TreeNode*> result;
            for (int i = l; i <= r; ++i) {
                for (auto left : dfs(l, i - 1)) {
                    for (auto right : dfs(i + 1, r)) {
                        result.push_back(new TreeNode(i, left, right));
                    }
                }
            }

            return result;
        };

        return dfs(1, n);
    }
};
