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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) return {};

        vector<vector<TreeNode*>> levelOrder = {{root}};
        while (true) {
            vector<TreeNode*> nextLevel;
            for (auto u : levelOrder.back()) {
                if (u->left) nextLevel.push_back(u->left);
                if (u->right) nextLevel.push_back(u->right);
            }
            if (nextLevel.empty()) break;
            levelOrder.push_back(nextLevel);
        }

        vector<vector<int>> result;
        while (!levelOrder.empty()) {
            result.push_back({});
            for (auto u : levelOrder.back()) {
                result.back().push_back(u->val);
            }
            levelOrder.pop_back();
        }

        return result;
    }
};
