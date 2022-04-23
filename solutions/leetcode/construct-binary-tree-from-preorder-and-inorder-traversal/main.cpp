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
        int preorder_pos = 0;
        unordered_map<int, int> inorder_index;
        for (int i = 0; i < inorder.size(); ++i) inorder_index[inorder[i]] = i;

        function<TreeNode*(int, int)> construct = [&](int l,
                                                      int r) -> TreeNode* {
            if (l > r) return nullptr;

            int v = preorder[preorder_pos++];
            auto node = new TreeNode(v);

            int m = inorder_index[v];
            node->left = construct(l, m - 1);
            node->right = construct(m + 1, r);

            return node;
        };

        return construct(0, preorder.size() - 1);
    }
};
