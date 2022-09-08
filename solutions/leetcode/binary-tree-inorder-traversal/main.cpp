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
        vector<int> ans;
        function<void(TreeNode*)> traverse = [&](TreeNode* u) -> void {
            if (!u) return;
            traverse(u->left);
            ans.push_back(u->val);
            traverse(u->right);
        };
        traverse(root);
        return ans;
    }
};

class Solution {
   public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        vector<pair<TreeNode*, bool>> st = {{root, false}};  // {node, seen}

        while (!st.empty()) {
            auto [u, seen] = st.back();
            st.pop_back();

            if (!u) continue;
            if (!seen) {
                st.push_back({u, true});
                st.push_back({u->left, false});
            } else {
                result.push_back(u->val);
                st.push_back({u->right, false});
            }
        }

        return result;
    }
};
