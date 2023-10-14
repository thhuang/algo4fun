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
        function<void(TreeNode*)> traverse = [&](TreeNode* u) -> void {
            if (u == nullptr) return;
            traverse(u->left);
            order.push_back(u);
            traverse(u->right);
        };
        traverse(root);

        int i = 0;
        while (true) {
            if (order[i]->val > order[i + 1]->val) break;
            ++i;
        }
        int j = order.size() - 1;
        while (true) {
            if (order[j - 1]->val > order[j]->val) break;
            --j;
        }
        swap(order[i]->val, order[j]->val);
    }
};

class Solution {
   public:
    void recoverTree(TreeNode* root) {
        TreeNode* p;

        p = nullptr;
        TreeNode* a = nullptr;
        function<void(TreeNode*)> inorder = [&](TreeNode* u) -> void {
            if (u == nullptr || a != nullptr) return;
            inorder(u->left);
            if (p != nullptr && p->val > u->val) {
                a = p;
                return;
            }
            p = u;
            inorder(u->right);
        };
        inorder(root);

        p = nullptr;
        TreeNode* b = nullptr;
        function<void(TreeNode*)> rinorder = [&](TreeNode* u) -> void {
            if (u == nullptr || b != nullptr) return;
            rinorder(u->right);
            if (p != nullptr && p->val < u->val) {
                b = p;
                return;
            }
            p = u;
            rinorder(u->left);
        };
        rinorder(root);

        swap(a->val, b->val);
    }
};
