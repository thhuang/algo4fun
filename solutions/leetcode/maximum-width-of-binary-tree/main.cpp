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
    typedef unsigned long long ll;

   public:
    int widthOfBinaryTree(TreeNode* root) {
        vector<array<int, 2>> level_range;
        vector<tuple<TreeNode*, ll>> q = {{root, 1}};

        ll result = 0;
        while (!q.empty()) {
            vector<tuple<TreeNode*, ll>> new_q;

            ll mn = numeric_limits<ll>::max();
            ll mx = numeric_limits<ll>::min();

            for (auto [u, i] : q) {
                mn = min(mn, i);
                mx = max(mn, i);

                if (u->left) new_q.push_back({u->left, i * 2});
                if (u->right) new_q.push_back({u->right, i * 2 + 1});
            }

            result = max(result, mx - mn + 1);
            q = move(new_q);
        }

        return result;
    }
};
