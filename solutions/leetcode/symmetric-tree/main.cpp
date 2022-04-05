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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        deque<TreeNode*> q0 = {root}, q1 = {root};
        while (!empty(q0) && !empty(q1)) {
            auto n0 = q0.front();
            auto n1 = q1.front();
            q0.pop_front(), q1.pop_front();

            if (n0 == nullptr && n1 == nullptr) continue;
            if (n0 == nullptr || n1 == nullptr) return false;
            if (n0->val != n1->val) return false;

            q0.push_back(n0->left), q0.push_back(n0->right);
            q1.push_back(n1->right), q1.push_back(n1->left);
        }
        return empty(q0) == empty(q1);
    }
};
