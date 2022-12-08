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
    void collectLeaves(TreeNode* u, vector<int>& leaves) {
        if (u == nullptr) return;
        if (u->left == nullptr && u->right == nullptr) {
            leaves.push_back(u->val);
            return;
        }
        collectLeaves(u->left, leaves);
        collectLeaves(u->right, leaves);
    }

   public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        collectLeaves(root1, leaves1);
        collectLeaves(root2, leaves2);
        return leaves1 == leaves2;
    }
};
