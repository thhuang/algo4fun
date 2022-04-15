/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
   public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        vector<Node*> q = {root};
        while (!q.empty()) {
            vector<Node*> new_q;
            for (int i = 0; i < q.size(); ++i) {
                if (i + 1 < q.size()) q[i]->next = q[i + 1];
                if (q[i]->left) new_q.push_back({q[i]->left});
                if (q[i]->right) new_q.push_back({q[i]->right});
            }
            q = move(new_q);
        }
        return root;
    }
};
