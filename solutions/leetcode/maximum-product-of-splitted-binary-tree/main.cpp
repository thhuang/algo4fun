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
    typedef long long ll;
    const int mod = 1e9 + 7;

   public:
    int maxProduct(TreeNode* root) {
        int sum = 0;
        function<void(TreeNode*)> collect = [&](TreeNode* u) -> void {
            if (u == nullptr) return;
            sum += u->val;
            collect(u->left);
            collect(u->right);
        };
        collect(root);

        ll result = 0;
        function<ll(TreeNode*)> search = [&](TreeNode* u) -> ll {
            if (u == nullptr) return 0;
            ll l = search(u->left);
            ll r = search(u->right);
            result = max(result, max(l * (sum - l), r * (sum - r)));
            return l + r + u->val;
        };
        search(root);

        return result % mod;
    }
};
