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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, unordered_map<bool, int>> cache;
        function<int(TreeNode*, bool)> dfs = [&](TreeNode* u,
                                                 bool can_rob) -> int {
            if (!u) return 0;
            if (cache[u].count(can_rob)) return cache[u][can_rob];
            int v = can_rob ? u->val : 0;
            return cache[u][can_rob] =
                       max(dfs(u->left, false) + dfs(u->right, false) + v,
                           dfs(u->left, true) + dfs(u->right, true));
        };
        return dfs(root, true);
    }
};

class Solution {
   public:
    int rob(TreeNode* root) {
        function<array<int, 2>(TreeNode*)> dfs =
            [&](TreeNode* u) -> array<int, 2> {
            if (!u) return {0, 0};
            auto [lw, lwo] = dfs(u->left);
            auto [rw, rwo] = dfs(u->right);
            return {max(lwo + rwo + u->val, lw + rw), lw + rw};
        };
        return dfs(root)[0];
    }
};
