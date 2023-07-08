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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        unordered_map<int, int> inorderToIndex;
        for (int i = 0; i < n; ++i) {
            inorderToIndex[inorder[i]] = i;
        }

        function<TreeNode*(int&, int, int)> build = [&](int& p, int il,
                                                        int ir) -> TreeNode* {
            if (il > ir) return nullptr;
            int v = postorder[p--];
            int i = inorderToIndex[v];
            auto r = build(p, i + 1, ir);
            auto l = build(p, il, i - 1);
            return new TreeNode(v, l, r);
        };

        int i = n - 1;
        return build(i, 0, n - 1);
    }
};
