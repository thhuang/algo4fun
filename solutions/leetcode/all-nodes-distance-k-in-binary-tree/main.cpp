/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;

        function<void(TreeNode*, int)> collect = [&](TreeNode* u,
                                                     int d) -> void {
            if (!u) return;
            if (d == 0) {
                result.push_back(u->val);
                return;
            }
            collect(u->left, d - 1);
            collect(u->right, d - 1);
        };

        function<int(TreeNode*)> search = [&](TreeNode* u) -> int {
            if (u == nullptr) return -1;
            if (u == target) {
                collect(u, k);
                return k - 1;
            }
            if (int l = search(u->left); l != -1) {
                l == 0 ? collect(u, 0) : collect(u->right, l - 1);
                return l - 1;
            }
            if (int r = search(u->right); r != -1) {
                r == 0 ? collect(u, 0) : collect(u->left, r - 1);
                return r - 1;
            }
            return -1;
        };

        search(root);

        return result;
    }
};
