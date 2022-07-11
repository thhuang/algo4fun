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

class Solution {
   public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* u, int d) -> void {
            if (!u) return;
            if (d == result.size()) result.push_back(u->val);
            dfs(u->right, d + 1);
            dfs(u->left, d + 1);
        };
        dfs(root, 0);
        return result;
    }
};
