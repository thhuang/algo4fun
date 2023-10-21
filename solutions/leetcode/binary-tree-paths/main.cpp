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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;

        vector<int> path;
        function<void(TreeNode*)> dfs = [&](TreeNode* u) -> void {
            if (u == nullptr) return;
            if (u->left == nullptr && u->right == nullptr) {
                stringstream ss;
                for (int v : path) {
                    ss << v << "->";
                }
                ss << u->val;
                result.push_back(ss.str());
                return;
            }

            path.push_back(u->val);
            dfs(u->left);
            dfs(u->right);
            path.pop_back();
        };

        dfs(root);

        return result;
    }
};
