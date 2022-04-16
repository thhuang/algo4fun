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
class BSTIterator {
    bool first_next_ = true;
    vector<TreeNode*> path_;

   public:
    BSTIterator(TreeNode* root) {
        auto pos = root;
        while (true) {
            path_.push_back(pos);
            if (pos->left == nullptr) break;
            pos = pos->left;
        }
    }

    bool hasNext() {
        if (first_next_) return true;

        int curr_val = path_.back()->val;
        int next_val = next();
        if (curr_val == next_val) return false;
        prev();

        return true;
    }

    int next() {
        if (first_next_) {
            first_next_ = false;
            return path_.back()->val;
        }

        if (path_.back()->right) {
            path_.push_back(path_.back()->right);
            while (path_.back()->left) path_.push_back(path_.back()->left);
            return path_.back()->val;
        }

        auto path = path_;
        while (true) {
            auto curr = path.back();
            path.pop_back();
            if (path.empty()) break;
            if (path.back()->left == curr) {
                path_ = move(path);
                break;
            }
        }

        return path_.back()->val;
    }

    bool hasPrev() {
        int curr_val = path_.back()->val;
        int prev_val = prev();
        if (curr_val == prev_val) return false;
        next();
        return true;
    }

    int prev() {
        if (path_.back()->left) {
            path_.push_back(path_.back()->left);
            while (path_.back()->right) path_.push_back(path_.back()->right);
            return path_.back()->val;
        }

        auto path = path_;
        while (true) {
            auto curr = path.back();
            path.pop_back();
            if (path.empty()) break;
            if (path.back()->right == curr) {
                path_ = move(path);
                break;
            }
        }

        return path_.back()->val;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */
