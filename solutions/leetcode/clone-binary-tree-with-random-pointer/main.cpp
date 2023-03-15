/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left),
 * right(right), random(random) {}
 * };
 */

class Solution {
   public:
    NodeCopy *copyRandomBinaryTree(Node *root) {
        unordered_map<Node *, NodeCopy *> mp;

        function<NodeCopy *(Node *)> construct = [&construct,
                                                  &mp](Node *u) -> NodeCopy * {
            if (u == nullptr) return nullptr;
            NodeCopy *v = mp[u] = new NodeCopy(u->val);
            v->left = construct(u->left);
            v->right = construct(u->right);
            return v;
        };
        construct(root);

        function<void(Node *)> patch = [&patch, &mp](Node *u) -> void {
            if (u == nullptr) return;
            auto v = mp[u];
            v->random = mp[u->random];
            patch(u->left);
            patch(u->right);
        };
        patch(root);

        return mp[root];
    }
};
