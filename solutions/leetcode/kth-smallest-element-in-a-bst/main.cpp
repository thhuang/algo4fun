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
    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        function<TreeNode*(TreeNode*)> inorder =
            [&](TreeNode* node) -> TreeNode* {
            if (!node) return nullptr;
            if (auto res = inorder(node->left); res) return res;
            if (++i == k) return node;
            if (auto res = inorder(node->right); res) return res;
            return nullptr;
        };
        if (auto res = inorder(root); res) return res->val;
        return 0;
    }
};

class Solution {
   public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* p = root;
        vector<TreeNode*> left_path = {};
        while (p->left) left_path.push_back(p), p = p->left;

        function<void()> forward = [&]() -> void {
            if (p->right) {
                p = p->right;
                while (p->left) left_path.push_back(p), p = p->left;
                return;
            }
            p = left_path.back();
            left_path.pop_back();
        };

        for (int i = 1; i < k; ++i) forward();

        return p->val;
    }
};

class Solution {
   public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* p = root;
        vector<TreeNode*> left_path = {};
        while (p) left_path.push_back(p), p = p->left;

        function<void()> forward = [&left_path]() -> void {
            auto p = left_path.back()->right;
            left_path.pop_back();
            while (p) left_path.push_back(p), p = p->left;
        };

        for (int i = 1; i < k; ++i) forward();

        return left_path.back()->val;
    }
};
