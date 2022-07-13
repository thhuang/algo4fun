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

class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* u, int lv) -> void {
            if (u == nullptr) return;
            if (result.size() == lv) result.push_back({});
            result[lv].push_back(u->val);
            dfs(u->left, lv + 1);
            dfs(u->right, lv + 1);
        };
        dfs(root, 0);
        return result;
    }
};
