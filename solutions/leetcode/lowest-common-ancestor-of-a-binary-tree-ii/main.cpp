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
        function<bool(TreeNode*, TreeNode*, vector<TreeNode*>&)> search =
            [&search](TreeNode* u, TreeNode* t,
                      vector<TreeNode*>& path) -> bool {
            if (u == nullptr) return false;
            path.push_back(u);
            if (u == t) return true;
            if (search(u->left, t, path)) return true;
            if (search(u->right, t, path)) return true;
            path.pop_back();
            return false;
        };

        vector<TreeNode*> pPath;
        search(root, p, pPath);

        vector<TreeNode*> qPath;
        search(root, q, qPath);

        TreeNode* result = nullptr;
        for (int i = 0; i < min(pPath.size(), qPath.size()); ++i) {
            if (pPath[i] != qPath[i]) break;
            result = pPath[i];
        }

        return result;
    }
};
