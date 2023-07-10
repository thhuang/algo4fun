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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        int l = root->left ? minDepth(root->left) : numeric_limits<int>::max();
        int r = root->right ? minDepth(root->right) : numeric_limits<int>::max();
        return 1 + min(l, r);
    }
};

class Solution {
   public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        while (!q.empty()) {
            auto [u, d] = q.front();
            q.pop();

            if (!u->left && !u->right) return d;
            if (u->left) q.push({u->left, d + 1});
            if (u->right) q.push({u->right, d + 1});
        }

        return 0;
    }
};
