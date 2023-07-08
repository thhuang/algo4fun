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
        unordered_map<int, int> inorderToIndex;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderToIndex[inorder[i]] = i;
        }

        function<TreeNode*(int&, int, int)> build = [&](int& p, int il,
                                                        int ir) -> TreeNode* {
            if (il > ir) return nullptr;
            int v = preorder[p++];
            int i = inorderToIndex[v];
            return new TreeNode(v, build(p, il, i - 1), build(p, i + 1, ir));
        };

        int i = 0;
        return build(i, 0, inorder.size() - 1);
    }
};
