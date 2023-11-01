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
    vector<int> findMode(TreeNode* root) {
        vector<int> result;

        int mxCount = 0;
        int currentCount = 0;
        int currentValue = numeric_limits<int>::min();

        function<void(TreeNode * u)> inorder = [&](TreeNode* u) -> void {
            if (!u) return;

            inorder(u->left);

            if (u->val == currentValue) {
                ++currentCount;
            } else {
                currentValue = u->val;
                currentCount = 1;
            }

            if (currentCount == mxCount) {
                result.push_back(u->val);
            } else if (currentCount > mxCount) {
                result = {currentValue};
                mxCount = currentCount;
            }

            inorder(u->right);
        };

        inorder(root);

        return result;
    }
};
