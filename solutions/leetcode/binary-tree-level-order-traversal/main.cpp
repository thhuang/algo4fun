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

        vector<vector<int>> result;

        vector<TreeNode*> q = {root};

        while (!q.empty()) {
            vector<TreeNode*> qNew;
            result.push_back({});

            for (TreeNode* u : q) {
                result.back().push_back(u->val);
                if (u->left) qNew.push_back({u->left});
                if (u->right) qNew.push_back({u->right});
            }

            q = move(qNew);
        }

        return result;
    }
};

class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* u, int lv) -> void {
            if (!u) return;
            if (result.size() == lv) result.push_back({});
            result[lv].push_back(u->val);
            dfs(u->left, lv + 1);
            dfs(u->right, lv + 1);
        };
        dfs(root, 0);
        return result;
    }
};
