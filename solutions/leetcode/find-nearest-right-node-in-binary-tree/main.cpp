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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* target) {
        deque<pair<TreeNode*, int>> q = {{root, 0}};
        while (!q.empty()) {
            auto [u, lv] = q.front();
            q.pop_front();

            if (u == target) {
                if (!q.empty() && q.front().second == lv)
                    return q.front().first;
                return nullptr;
            }
            if (u->left) q.push_back({u->left, lv + 1});
            if (u->right) q.push_back({u->right, lv + 1});
        }
        return nullptr;
    }
};
