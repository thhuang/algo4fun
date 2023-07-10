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
    bool is_first_call_of_next_ = true;
    vector<TreeNode*> path_;

    TreeNode* NextNode() {
        if (path_.back()->right) {
            auto p = path_.back()->right;
            while (p) path_.push_back(p), p = p->left;
            return path_.back();
        }

        auto new_path = path_;
        while (true) {
            auto prev = new_path.back();

            new_path.pop_back();
            if (new_path.empty()) return nullptr;

            auto curr = new_path.back();
            if (curr->left == prev) break;
        }

        path_ = new_path;
        return path_.back();
    }

   public:
    BSTIterator(TreeNode* root) {
        auto p = root;
        while (p) path_.push_back(p), p = p->left;
    }

    int next() {
        if (is_first_call_of_next_) {
            is_first_call_of_next_ = false;
        } else {
            NextNode();
        }
        return path_.back()->val;
    }

    bool hasNext() {
        if (is_first_call_of_next_) return true;

        auto curr_path = path_;
        auto next_node = NextNode();
        path_ = curr_path;

        return next_node != nullptr;
    }
};

class BSTIterator {
    vector<TreeNode*> path;

   public:
    BSTIterator(TreeNode* root) {
        path.push_back(root);
        while (path.back()->left) {
            path.push_back(path.back()->left);
        }
    }

    int next() {
        int result = path.back()->val;
        TreeNode* u = path.back()->right;
        path.pop_back();
        while (u) {
            path.push_back(u);
            u = u->left;
        }
        return result;
    }

    bool hasNext() { return !path.empty(); }
};

class BSTIterator {
    vector<TreeNode*> greater_nodes_;

    void toSmallestNode(TreeNode* node) {
        while (node) greater_nodes_.push_back(node), node = node->left;
    }

   public:
    BSTIterator(TreeNode* root) { toSmallestNode(root); }

    int next() {
        auto curr = greater_nodes_.back();
        greater_nodes_.pop_back();
        toSmallestNode(curr->right);
        return curr->val;
    }

    bool hasNext() { return !greater_nodes_.empty(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
