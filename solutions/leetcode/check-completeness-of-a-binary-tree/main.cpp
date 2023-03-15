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
    bool isCompleteTree(TreeNode* root) {
        deque<TreeNode*> q = {root};
        bool foundLastNode = false;
        while (!q.empty()) {
            auto u = q.front();
            q.pop_front();

            if (u->left == nullptr && u->right != nullptr) return false;
            if (u->left == nullptr && u->right == nullptr) {
                foundLastNode = true;
                continue;
            }
            if (u->left != nullptr) {
                if (foundLastNode) return false;
                q.push_back(u->left);
                if (u->right == nullptr) {
                    foundLastNode = true;
                } else {
                    q.push_back(u->right);
                }
            }
        }
        return true;
    }
};
