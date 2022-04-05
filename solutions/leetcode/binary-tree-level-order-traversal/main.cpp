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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> ans;

        deque<TreeNode*> q;
        q.push_back(root);
        while (!empty(q)) {
            deque<TreeNode*> new_q;
            ans.push_back({});
            for (auto n : q) {
                if (!n) continue;
                ans.back().push_back(n->val);
                if (n->left) new_q.push_back(n->left);
                if (n->right) new_q.push_back(n->right);
            }
            q = new_q;
        }

        return ans;
    }
};
