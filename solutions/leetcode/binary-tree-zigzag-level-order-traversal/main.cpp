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
        vector<vector<int>> result;
        vector<TreeNode*> q;
        if (root) q.push_back(root);

        while (!q.empty()) {
            result.push_back({});
            if (result.size() % 2) {
                for (auto it = q.begin(); it != q.end(); ++it)
                    result.back().push_back((*it)->val);
            } else {
                for (auto it = q.rbegin(); it != q.rend(); ++it)
                    result.back().push_back((*it)->val);
            }

            vector<TreeNode*> new_q;
            for (TreeNode* u : q) {
                if (u->left) new_q.push_back(u->left);
                if (u->right) new_q.push_back(u->right);
            }
            q = move(new_q);
        }

        return result;
    }
};
