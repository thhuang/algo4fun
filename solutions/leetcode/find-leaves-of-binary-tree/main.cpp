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
    vector<vector<int>> findLeaves(TreeNode* root) {
        unordered_map<int, vector<int>> layers;

        function<int(TreeNode*)> search = [&](TreeNode* node) -> int {
            if (!node) return 0;
            int d = max(search(node->left), search(node->right));
            layers[d].push_back(node->val);
            return d + 1;
        };

        int depth = search(root);

        vector<vector<int>> result(depth);
        for (int i = 0; i < depth; ++i) result[i] = layers[i];

        return result;
    }
};

class Solution {
   public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        function<int(TreeNode*)> search = [&](TreeNode* node) -> int {
            if (!node) return 0;
            int d = max(search(node->left), search(node->right));
            if (d == result.size()) result.push_back({});
            result[d].push_back(node->val);
            return d + 1;
        };
        search(root);
        return result;
    }
};

class Solution {
   public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        function<int(TreeNode*)> dfs = [&](TreeNode* u) -> int {
            if (!u) return 0;
            int v = max(dfs(u->left), dfs(u->right));
            if (result.size() == v) result.push_back({});
            result[v].push_back(u->val);
            return v + 1;
        };
        dfs(root);
        return result;
    }
};
