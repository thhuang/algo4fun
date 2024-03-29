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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        function<TreeNode*(int, int)> build = [&](int l, int r) -> TreeNode* {
            if (l > r) return nullptr;
            int m = l + (r - l) / 2;
            return new TreeNode(nums[m], build(l, m - 1), build(m + 1, r));
        };
        return build(0, nums.size() - 1);
    }
};
