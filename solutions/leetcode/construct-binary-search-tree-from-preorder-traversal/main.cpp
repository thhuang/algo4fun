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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        function<TreeNode*(int&, int, int)> construct =
            [&](int& i, int l, int r) -> TreeNode* {
            auto u = new TreeNode(preorder[i++]);
            if (i < preorder.size() && l <= preorder[i] && preorder[i] < u->val)
                u->left = construct(i, l, u->val - 1);
            if (i < preorder.size() && u->val < preorder[i] && preorder[i] <= r)
                u->right = construct(i, u->val + 1, r);
            return u;
        };
        int i = 0;
        return construct(i, numeric_limits<int>::min(),
                         numeric_limits<int>::max());
    }
};
