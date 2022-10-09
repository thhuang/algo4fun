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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> nums;
        function<bool(TreeNode*)> search = [&](TreeNode* node) -> bool {
            if (!node) return false;
            if (nums.count(k - node->val)) return true;
            nums.insert(node->val);
            return search(node->left) || search(node->right);
        };
        return search(root);
    }
};

class Solution {
   public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        function<void(TreeNode*)> inorder = [&](TreeNode* u) -> void {
            if (!u) return;
            inorder(u->left);
            nums.push_back(u->val);
            inorder(u->right);
        };
        inorder(root);
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int v = nums[l] + nums[r];
            if (v == k) return true;
            if (v < k) {
                ++l;
            } else {  // v > k
                --r;
            }
        }
        return false;
    }
};
