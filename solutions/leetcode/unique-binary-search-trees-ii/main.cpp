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
        function<vector<TreeNode*>(int, int)> generate =
            [&](int l, int r) -> vector<TreeNode*> {
            if (l > r) return {nullptr};
            vector<TreeNode*> result;
            for (int i = l; i <= r; ++i) {
                auto left = generate(l, i - 1);
                auto right = generate(i + 1, r);
                for (auto ll : left) {
                    for (auto rr : right) {
                        result.push_back(new TreeNode(i, ll, rr));
                    }
                }
            }
            return result;
        };
        return generate(1, n);
    }
};
