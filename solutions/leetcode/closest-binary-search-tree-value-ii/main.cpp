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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        deque<int> result;

        bool found = false;

        function<void(TreeNode*)> inorder = [&](TreeNode* u) -> void {
            if (u == nullptr) return;
            if (found) return;

            inorder(u->left);

            result.push_back(u->val);
            if (result.size() > k) {
                double diffLeft = abs(target - result.front());
                double diffRight = abs(target - result.back());
                if (diffLeft > diffRight) {
                    result.pop_front();
                } else {
                    result.pop_back();
                    found = true;
                }
            }

            inorder(u->right);
        };
        inorder(root);

        return {result.begin(), result.end()};
    }
};
