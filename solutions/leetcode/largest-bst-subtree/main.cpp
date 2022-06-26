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
    struct Res {
        int mn, mx, sz = 0;
    };

   public:
    int largestBSTSubtree(TreeNode* root) {
        int result = 0;

        function<Res(TreeNode*)> dfs = [&](TreeNode* u) -> Res {
            if (u == nullptr) return Res();

            auto l = dfs(u->left);
            auto r = dfs(u->right);

            Res res = {u->val, u->val, 1};
            if (u->left) {
                if (l.sz && l.mx < u->val) {
                    res.mn = l.mn;
                    res.sz += l.sz;
                } else {
                    res.sz = 0;
                }
            }
            if (res.sz && u->right) {
                if (r.sz && u->val < r.mn) {
                    res.mx = r.mx;
                    res.sz += r.sz;
                } else {
                    res.sz = 0;
                }
            }

            result = max(result, res.sz);

            return res;
        };

        dfs(root);

        return result;
    }
};
