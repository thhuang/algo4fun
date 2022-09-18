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
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<vector<TreeNode*>> tree = {{root}};
        while (tree.back().front()->left) {
            int n = tree.size();
            tree.push_back({});
            for (auto u : tree[n - 1]) {
                tree[n].push_back(u->left);
                tree[n].push_back(u->right);
            }
        }

        for (int i = 0; i < tree.size() - 1; ++i) {
            if (i % 2 == 0) reverse(tree[i + 1].begin(), tree[i + 1].end());
            for (int j = 0; j < tree[i].size(); ++j) {
                tree[i][j]->left = tree[i + 1][j * 2];
                tree[i][j]->right = tree[i + 1][j * 2 + 1];
            }
        }

        return root;
    }
};
