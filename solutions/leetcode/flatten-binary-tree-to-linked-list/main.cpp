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
        while (root) {
            auto p = root->left;
            while (p && p->right) p = p->right;
            if (p) {
                p->right = root->right;
                root->right = root->left;
            }
            root->left = nullptr;
            root = root->right;
        }
    }
};

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

class Solution {
   public:
    void flatten(TreeNode* root) {
        for (auto p = root; p; p = p->right) {
            if (!p->left) continue;

            TreeNode* r = p->left;
            while (r->right) r = r->right;
            r->right = p->right;
            p->right = p->left;
            p->left = nullptr;
        }
    }
};

class Solution {
   public:
    void flatten(TreeNode* root) {
        function<TreeNode*(TreeNode*)> f = [&](TreeNode* u) -> TreeNode* {
            if (!u) return nullptr;
            if (!u->left && !u->right) return u;

            auto leftEnd = f(u->left);
            auto rightEnd = f(u->right);

            if (leftEnd) {
                leftEnd->right = u->right;
                u->right = u->left;
                u->left = nullptr;
            }

            return rightEnd ? rightEnd : leftEnd;
        };

        f(root);
    }
};
