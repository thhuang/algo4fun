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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        vector<int> result = {root->val};
        vector<TreeNode*> q = {root};
        while (true) {
            vector<TreeNode*> new_q;
            for (TreeNode* u : q) {
                if (u->left) new_q.push_back(u->left);
                if (u->right) new_q.push_back(u->right);
            }
            if (new_q.empty()) break;
            result.push_back(new_q.back()->val);
            q = move(new_q);
        }

        return result;
    }
};
