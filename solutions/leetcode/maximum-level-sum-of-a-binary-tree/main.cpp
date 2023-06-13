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
    int maxLevelSum(TreeNode* root) {
        int result = 0;
        int mx = numeric_limits<int>::min();
        vector<TreeNode*> q = {root};
        for (int i = 1; !q.empty(); ++i) {
            vector<TreeNode*> qNew;
            int v = 0;
            for (auto u : q) {
                v += u->val;
                if (u->left) qNew.push_back(u->left);
                if (u->right) qNew.push_back(u->right);
            }
            q = move(qNew);
            if (mx < v) {
                mx = v;
                result = i;
            }
        }
        return result;
    }
};
