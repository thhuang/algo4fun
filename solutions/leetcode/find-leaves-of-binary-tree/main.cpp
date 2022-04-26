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
