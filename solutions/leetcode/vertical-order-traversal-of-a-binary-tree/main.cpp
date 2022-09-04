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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        function<int(TreeNode*, int)> dfs = [&](TreeNode* u, int x) -> int {
            if (!u) return x + 1;
            int v = x;
            v = min(v, dfs(u->left, x - 1));
            v = min(v, dfs(u->right, x + 1));
            return v;
        };
        int offset = -dfs(root, 0);

        vector<vector<vector<int>>> nodes;
        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, offset, 0});

        while (!q.empty()) {
            auto [u, x, y] = q.front();
            q.pop();

            while (nodes.size() <= x) nodes.push_back({});
            while (nodes[x].size() <= y) nodes[x].push_back({});

            nodes[x][y].push_back(u->val);

            if (u->left) q.push({u->left, x - 1, y + 1});
            if (u->right) q.push({u->right, x + 1, y + 1});
        }

        vector<vector<int>> result;
        for (int i = 0; i < nodes.size(); ++i) {
            result.push_back({});
            for (int j = 0; j < nodes[i].size(); ++j) {
                sort(nodes[i][j].begin(), nodes[i][j].end());
                for (int v : nodes[i][j]) result.back().push_back(v);
            }
        }

        return result;
    }
};
