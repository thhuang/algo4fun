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
    struct Node {
        TreeNode *u, *p;
    };

   public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        vector<Node> nodes = {{root, nullptr}};

        while (!nodes.empty()) {
            unordered_map<TreeNode*, bool> seen;
            vector<Node> nextLevelNodes;

            for (auto [u, p] : nodes) {
                if (auto r = u->right; r != nullptr && seen[r]) {
                    (p->left == u ? p->left : p->right) = nullptr;
                    return root;
                }

                seen[u] = true;
                if (u->right != nullptr)
                    nextLevelNodes.push_back({u->right, u});
                if (u->left != nullptr) nextLevelNodes.push_back({u->left, u});
            }

            nodes = nextLevelNodes;
        }

        return nullptr;
    }
};

class Solution {
    struct Node {
        TreeNode *u, *p;
    };

   public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        queue<Node> q;
        q.push({root, nullptr});

        while (!q.empty()) {
            unordered_map<TreeNode*, bool> seen;

            int n = q.size();
            while (n-- > 0) {
                auto [u, p] = q.front();
                q.pop();

                if (auto r = u->right; r != nullptr && seen[r]) {
                    (p->left == u ? p->left : p->right) = nullptr;
                    return root;
                }

                seen[u] = true;
                if (u->right != nullptr) q.push({u->right, u});
                if (u->left != nullptr) q.push({u->left, u});
            }
        }

        return nullptr;
    }
};
