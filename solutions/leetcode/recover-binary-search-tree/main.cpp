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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> order;
        function<void(TreeNode*)> inorder = [&](TreeNode* u) -> void {
            if (u == nullptr) return;
            inorder(u->left);
            order.emplace_back(u);
            inorder(u->right);
        };

        inorder(root);

        TreeNode* a = order.front();
        int i = 0;
        while (order[i]->val >= a->val) a = order[i++];

        TreeNode* b = a;
        while (i < order.size() && order[i]->val <= a->val) b = order[i++];

        swap(a->val, b->val);
    }
};
