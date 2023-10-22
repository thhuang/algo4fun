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
    const double epsilon = 1e-6;

   public:
    int closestValue(TreeNode* root, double target) {
        int value = root->val;
        double dist = abs(root->val - target);

        function<void(TreeNode*)> search = [&](TreeNode* u) -> void {
            if (u == nullptr) return;

            double d = abs(u->val - target);
            bool lt = d < dist - epsilon;
            bool eq = dist - epsilon < d && d < dist + epsilon;
            if (lt || (eq && u->val < value)) {
                dist = d;
                value = u->val;
            }

            target < u->val ? search(u->left) : search(u->right);
        };
        search(root);

        return value;
    }
};
