/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        function<void(TreeNode*)> preorder = [&](TreeNode* u) -> void {
            if (!u) {
                s += ":";
                return;
            }
            s += ":" + to_string(u->val);
            preorder(u->left);
            preorder(u->right);
        };
        preorder(root);
        return s.substr(1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        function<TreeNode*()> construct = [&]() -> TreeNode* {
            string s;
            if (!getline(ss, s, ':')) return nullptr;
            if (s == "") return nullptr;

            auto node = new TreeNode(stoi(s));
            node->left = construct();
            node->right = construct();

            return node;
        };
        return construct();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
