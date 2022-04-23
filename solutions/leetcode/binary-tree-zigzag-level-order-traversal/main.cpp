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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> result = {{root->val}};
        vector<TreeNode*> q = {root};
        int level = 0;
        while (true) {
            vector<TreeNode*> new_q;
            vector<int> row;

            for (auto u : q) {
                if (u->left)
                    new_q.push_back(u->left), row.push_back(u->left->val);
                if (u->right)
                    new_q.push_back(u->right), row.push_back(u->right->val);
            }

            if (row.empty()) break;
            if (++level & 1) reverse(row.begin(), row.end());
            result.emplace_back(row);
            q = move(new_q);
        }

        return result;
    }
};
