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
    int deepestLeavesSum(TreeNode* root) {
        vector<TreeNode*> q = {root};
        while (!q.empty()) {
            vector<TreeNode*> new_q;
            int result = 0;
            for (auto u : q) {
                result += u->val;
                if (u->left) new_q.push_back(u->left);
                if (u->right) new_q.push_back(u->right);
            }
            if (new_q.empty()) {
                return result;
            }
            q = move(new_q);
        }
        return 0;
    }
};
