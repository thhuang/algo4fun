/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* root = nullptr;
    bool foundP = false;
    bool foundQ = false;

   public:
    TreeNode* lowestCommonAncestor(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (!node) return nullptr;

        if (!root) root = node;

        TreeNode* result = nullptr;

        if (node == p) foundP = true, result = node;
        if (node == q) foundQ = true, result = node;

        auto l = lowestCommonAncestor(node->left, p, q);
        auto r = lowestCommonAncestor(node->right, p, q);

        if (!result && !l && !r) return nullptr;

        if (root == node && (!foundP || !foundQ)) return nullptr;

        if (l && r) return node;
        if (result) return result;
        return l ? l : r;
    }
};

class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pPath, qPath;

        vector<TreeNode*> path;
        function<void(TreeNode*)> search = [&](TreeNode* u) -> void {
            if (!u) return;

            path.push_back(u);

            if (u == p) pPath = path;
            if (u == q) qPath = path;

            search(u->left);
            search(u->right);

            path.pop_back();
        };

        search(root);

        if (pPath.empty() || qPath.empty()) return nullptr;

        TreeNode* result;
        for (int i = 0; i < min(pPath.size(), qPath.size()); ++i) {
            if (pPath[i] == qPath[i]) result = pPath[i];
        }

        return result;
    }
};
