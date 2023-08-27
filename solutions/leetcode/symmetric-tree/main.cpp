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
        function<bool(TreeNode*, TreeNode*)> check = [&](TreeNode* a,
                                                         TreeNode* b) -> bool {
            if (!a && !b) return true;
            if (!a || !b || a->val != b->val) return false;
            return check(a->left, b->right) && check(a->right, b->left);
        };
        return check(root->left, root->right);
    }
};

class Solution {
   public:
    bool isSymmetric(TreeNode* root) {
        queue<array<TreeNode*, 2>> q;
        q.push({root->left, root->right});

        while (!q.empty()) {
            auto [l, r] = q.front();
            q.pop();

            if (!l && !r) continue;
            if (!l || !r || l->val != r->val) return false;

            q.push({l->left, r->right});
            q.push({l->right, r->left});
        }

        return true;
    }
};
