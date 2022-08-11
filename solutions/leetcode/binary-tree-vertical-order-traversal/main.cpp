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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        unordered_map<int, vector<int>> cols;
        int mn = 0;

        queue<pair<TreeNode*, int>> q;
        if (root) q.push({root, 0});

        while (!q.empty()) {
            auto [u, i] = q.front();
            q.pop();

            cols[i].push_back(u->val);
            mn = min(mn, i);

            if (u->left) q.push({u->left, i - 1});
            if (u->right) q.push({u->right, i + 1});
        }

        vector<vector<int>> result;
        for (int i = mn; cols.count(i); ++i) result.emplace_back(move(cols[i]));

        return result;
    }
};
