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
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> result;
        function<int(TreeNode*)> search = [&](TreeNode* u) -> int {
            if (!u) return 0;
            int l = search(u->left);
            int r = search(u->right);
            if (!(l > 0 && r > 0) && !(l == 0 && r == 0))
                result.push_back(l + r);
            return u->val;
        };
        search(root);
        return result;
    }
};
