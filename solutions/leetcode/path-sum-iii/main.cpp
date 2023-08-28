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

   public:
    int pathSum(TreeNode* root, int targetSum) {
        int result = 0;

        unordered_map<ll, int> targetCount = {{targetSum, 1}};

        ll sum = 0;
        function<void(TreeNode*)> search = [&](TreeNode* u) -> void {
            if (!u) return;
            sum += u->val;
            result += targetCount[sum];

            ++targetCount[sum + targetSum];
            search(u->left);
            search(u->right);
            --targetCount[sum + targetSum];

            sum -= u->val;
        };

        search(root);

        return result;
    }
};
