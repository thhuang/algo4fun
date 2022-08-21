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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* u, int p) -> void {
            if (p != -1) adj[u->val].push_back(p);
            if (u->left) {
                adj[u->val].push_back(u->left->val);
                dfs(u->left, u->val);
            }
            if (u->right) {
                adj[u->val].push_back(u->right->val);
                dfs(u->right, u->val);
            }
        };
        dfs(root, -1);

        function<int(int, int)> search = [&](int u, int p) -> int {
            int d = 0;
            for (int v : adj[u]) {
                if (v == p) continue;
                d = max(d, search(v, u) + 1);
            }
            return d;
        };

        return search(start, -1);
    }
};
