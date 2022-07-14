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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int, int> inorder_index;
        for (int i = 0; i < n; ++i) inorder_index[inorder[i]] = i;

        int p = 0;
        function<TreeNode*(int, int)> construct = [&](int l,
                                                      int r) -> TreeNode* {
            if (l > r) return nullptr;
            int v = preorder[p++];
            int m = inorder_index[v];
            return new TreeNode(v, construct(l, m - 1), construct(m + 1, r));
        };

        return construct(0, n - 1);
    }
};
