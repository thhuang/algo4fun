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
    int longestConsecutive(TreeNode* root) {
        int result = 1;

        function<pair<int, int>(TreeNode*)> dfs =
            [&](TreeNode* u) -> pair<int, int> {
            if (u == nullptr) return {0, 0};

            pair<int, int> r = {1, 1};
            if (u->right) {
                auto [dec, inc] = dfs(u->right);
                if (u->val == u->right->val - 1) r.first = dec + 1;
                if (u->val == u->right->val + 1) r.second = inc + 1;
            }

            pair<int, int> l = {1, 1};
            if (u->left) {
                auto [dec, inc] = dfs(u->left);
                if (u->val == u->left->val - 1) l.first = dec + 1;
                if (u->val == u->left->val + 1) l.second = inc + 1;
            }

            result = max(result,
                         max(r.first + l.second - 1, r.second + l.first - 1));

            return {max(l.first, r.first), max(l.second, r.second)};
        };

        dfs(root);

        return result;
    }
};

class Solution {
    struct Res {
        int inc, dec;

        int max() const { return ::max(inc, dec); }
    };

   public:
    int longestConsecutive(TreeNode* root) {
        int result = 0;

        function<Res(TreeNode*)> dfs = [&](TreeNode* u) -> Res {
            if (!u) return Res{0, 0};

            auto l = dfs(u->left);
            auto r = dfs(u->right);

            bool linc = u->left && u->left->val + 1 == u->val;
            bool ldec = u->left && u->left->val - 1 == u->val;
            bool rinc = u->right && u->right->val + 1 == u->val;
            bool rdec = u->right && u->right->val - 1 == u->val;

            auto res = Res{1, 1};
            if (linc) res.inc = max(res.inc, l.inc + 1);
            if (ldec) res.dec = max(res.dec, l.dec + 1);
            if (rinc) res.inc = max(res.inc, r.inc + 1);
            if (rdec) res.dec = max(res.dec, r.dec + 1);
            result = max(result, res.max());

            if (linc && rdec) result = max(result, l.inc + r.dec + 1);
            if (ldec && rinc) result = max(result, l.dec + r.inc + 1);

            return res;
        };

        dfs(root);

        return result;
    }
};
