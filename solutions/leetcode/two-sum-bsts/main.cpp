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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        vector<int> nums1;
        function<void(TreeNode*)> dfs1 = [&](TreeNode* u) -> void {
            if (u == nullptr) return;
            dfs1(u->left);
            nums1.push_back(u->val);
            dfs1(u->right);
        };
        dfs1(root1);

        int i = 0;
        function<bool(TreeNode*)> dfs2 = [&](TreeNode* u) -> bool {
            if (u == nullptr) return false;
            if (dfs2(u->right)) return true;
            while (i < nums1.size() && nums1[i] + u->val < target) ++i;
            if (i == nums1.size()) return false;
            if (nums1[i] + u->val == target) return true;
            if (dfs2(u->left)) return true;
            return false;
        };
        return dfs2(root2);
    }
};
