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

class Solution {
    struct Forward {
        TreeNode* curr;
        vector<TreeNode*> path;

        Forward(TreeNode* root) {
            curr = root;
            while (curr->left) {
                path.push_back(curr);
                curr = curr->left;
            }
        }

        bool next() {
            if (!curr->right) {
                if (path.empty()) return false;
                curr = path.back();
                path.pop_back();
                return true;
            }
            curr = curr->right;
            while (curr->left) {
                path.push_back(curr);
                curr = curr->left;
            }
            return true;
        }
    };

    struct Backward {
        TreeNode* curr;
        vector<TreeNode*> path;

        Backward(TreeNode* root) {
            curr = root;
            while (curr->right) {
                path.push_back(curr);
                curr = curr->right;
            }
        }

        bool next() {
            if (!curr->left) {
                if (path.empty()) return false;
                curr = path.back();
                path.pop_back();
                return true;
            }
            curr = curr->left;
            while (curr->right) {
                path.push_back(curr);
                curr = curr->right;
            }
            return true;
        }
    };

   public:
    bool findTarget(TreeNode* root, int k) {
        Forward forward(root);
        Backward backward(root);
        while (forward.curr != backward.curr) {
            int v = forward.curr->val + backward.curr->val;
            if (v == k) return true;
            if (v < k) {
                forward.next();
            } else {  // v > k
                backward.next();
            }
        }
        return false;
    }
};
