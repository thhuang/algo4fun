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
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;

        function<int(TreeNode*)> search = [&](TreeNode* u) -> int {
            if (!u) return 0;
            int l = search(u->left);
            int r = search(u->right);
            result = max(result, l + r + 1);
            return max(l, r) + 1;
        };

        search(root);

        return result - 1;
    }
};
