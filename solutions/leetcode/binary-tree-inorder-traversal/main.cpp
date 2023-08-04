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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        function<void(TreeNode*)> inorder = [&](TreeNode* u) -> void {
            if (!u) return;
            inorder(u->left);
            result.push_back(u->val);
            inorder(u->right);
        };
        inorder(root);
        return result;
    }
};

class Solution {
   public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;

        vector<pair<TreeNode*, bool>> workList = {{root, false}};
        while (!workList.empty()) {
            auto [u, visited] = workList.back();
            workList.pop_back();

            if (!u) continue;

            if (visited) {
                result.push_back(u->val);
            } else {
                workList.push_back({u->right, false});
                workList.push_back({u, true});
                workList.push_back({u->left, false});
            }
        }

        return result;
    }
};
