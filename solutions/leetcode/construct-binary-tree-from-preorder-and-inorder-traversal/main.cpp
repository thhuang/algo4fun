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

class Solution {
   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorder_index;
        for (int i = 0; i < inorder.size(); ++i)
            inorder_index.insert({inorder[i], i});

        function<TreeNode*(int&, int, int)> construct =
            [&](int& i, int l, int r) -> TreeNode* {
            if (i == preorder.size()) return nullptr;

            int v = preorder[i];
            int j = inorder_index[v];
            if (j < l || r < j) return nullptr;

            ++i;
            return new TreeNode(v, construct(i, l, j - 1), construct(i, j + 1, r));
        };

        int i = 0;
        return construct(i, 0, inorder.size() - 1);
    }
};
