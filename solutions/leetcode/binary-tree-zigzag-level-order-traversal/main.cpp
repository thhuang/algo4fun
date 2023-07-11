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

class Solution {
   public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> result;
        vector<TreeNode*> q = {root};
        bool forward = true;

        while (!q.empty()) {
            result.push_back({});
            vector<TreeNode*> new_q;

            for (auto u : q) {
                result.back().push_back(u->val);
                if (u->left) new_q.push_back(u->left);
                if (u->right) new_q.push_back(u->right);
            }

            if (!forward) reverse(result.back().begin(), result.back().end());

            q = move(new_q);
            forward = !forward;
        }

        return result;
    }
};

class Solution {
   public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        function<void(TreeNode*, int)> dfs = [&](TreeNode* u, int lv) -> void {
            if (!u) return;

            if (result.size() == lv) result.push_back({});

            result[lv].push_back(u->val);

            dfs(u->left, lv + 1);
            dfs(u->right, lv + 1);
        };

        dfs(root, 0);

        for (int i = 1; i < result.size(); i += 2) {
            reverse(result[i].begin(), result[i].end());
        }

        return result;
    }
};
