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
    enum State { require, covered, camera };

   public:
    int minCameraCover(TreeNode* root) {
        int result = 0;

        function<State(TreeNode*)> dfs = [&](TreeNode* u) -> State {
            if (!u) return covered;
            auto l = dfs(u->left);
            auto r = dfs(u->right);

            if (l == require || r == require) {
                ++result;
                return camera;
            }

            if (l == camera || r == camera) return covered;
            return require;
        };

        if (dfs(root) == require) ++result;

        return result;
    }
};
