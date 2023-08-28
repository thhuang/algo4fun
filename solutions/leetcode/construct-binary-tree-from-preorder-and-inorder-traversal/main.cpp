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
        unordered_map<int, int> valueToInorderIndex;
        for (int i = 0; i < n; ++i) {
            valueToInorderIndex[inorder[i]] = i;
        }

        function<TreeNode*(int&, int, int)> build = [&](int& p, int l, int r) -> TreeNode* {
            if (l > r) return nullptr;
            int v = preorder[p++];
            int i = valueToInorderIndex[v];
            return new TreeNode(v, build(p, l, i - 1), build(p, i + 1, r));
        };

        int p = 0;
        return build(p, 0, n - 1);
    }
};
