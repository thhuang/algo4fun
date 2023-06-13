/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   public:
    int pathSum(TreeNode* root, int targetSum) {
        int result = 0;
        
        unordered_map<long long, int> prefix;
        prefix[0] = 1;

        function<void(TreeNode*, long long)> dfs = [&](TreeNode* u, long long v) -> void {
            if (u == nullptr) return;    

            v += u->val;
            result += prefix[v - targetSum];

            ++prefix[v];
            dfs(u->left, v);
            dfs(u->right, v);
            --prefix[v];
        };

        dfs(root, 0);

        return result;
    }
};
