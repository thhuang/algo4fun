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
    void flatten(TreeNode* root) {
        if (!root) return;

        TreeNode dummy;
        auto p = &dummy;
        function<void(TreeNode*)> preorder = [&](TreeNode* u) -> void {
            if (u == nullptr) return;
            p->right = u;
            p = p->right;
            auto r = u->right;
            preorder(u->left);
            u->left = nullptr;
            preorder(r);
        };

        preorder(root);
    }
};

class Solution {
   public:
    void flatten(TreeNode* root) {
        TreeNode* p = root;

        while (p) {
            if (p->left) {
                TreeNode* r = p->left;
                while (r->right) r = r->right;
                r->right = p->right;
                p->right = p->left;
                p->left = nullptr;
            }

            p = p->right;
        }
    }
};
