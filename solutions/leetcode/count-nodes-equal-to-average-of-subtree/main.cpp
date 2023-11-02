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
    int averageOfSubtree(TreeNode* root) {
        int result = 0;
        function<array<int, 2>(TreeNode*)> search =
            [&](TreeNode* u) -> array<int, 2> {  // sum, count
            if (u == nullptr) return {0, 0};

            auto [ls, lc] = search(u->left);
            auto [rs, rc] = search(u->right);

            int sum = u->val + ls + rs;
            int count = 1 + lc + rc;
            int avg = sum / count;
            if (avg == u->val) ++result;

            return {sum, count};
        };
        search(root);
        return result;
    }
};

class Solution {
    struct Res {
        int sum, n;
    };

   public:
    int averageOfSubtree(TreeNode* root) {
        int result = 0;

        function<Res(TreeNode*)> dfs = [&](TreeNode* u) -> Res {
            if (u == nullptr) return {0, 0};

            int sum = u->val;
            int n = 1;

            auto [lsum, ln] = dfs(u->left);
            auto [rsum, rn] = dfs(u->right);

            sum += lsum + rsum;
            n += ln + rn;

            if (sum / n == u->val) ++result;

            return {sum, n};
        };
        dfs(root);

        return result;
    }
};
