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

        unordered_map<int, int> inorderValueToIndex;
        for (int i = 0; i < n; ++i) {
            inorderValueToIndex[inorder[i]] = i;
        }

        function<TreeNode*(pair<int, int>, pair<int, int>)> build =
            [&](pair<int, int> inorderRange,
                pair<int, int> postorderRange) -> TreeNode* {
            auto [il, ir] = inorderRange;
            auto [pl, pr] = postorderRange;

            if (il > ir) return nullptr;

            int p = pr;
            int v = postorder[p];
            int i = inorderValueToIndex[v];

            int l = i - il;
            int r = ir - i;

            auto node = new TreeNode(v, build({il, i - 1}, {pl, pl + l - 1}),
                                     build({i + 1, ir}, {pl + l, p - 1}));

            return node;
        };

        return build({0, n - 1}, {0, n - 1});
    }
};
