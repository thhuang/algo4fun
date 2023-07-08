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

class Solution {
   public:
    Node* connect(Node* root) {
        vector<Node*> left;

        function<void(Node*, int)> dfs = [&](Node* u, int d) -> void {
            if (u == nullptr) return;

            if (left.size() == d) {
                left.push_back(u);
            } else {
                left[d] = left[d]->next = u;
            }

            dfs(u->left, d + 1);
            dfs(u->right, d + 1);
        };

        dfs(root, 0);

        return root;
    }
};

class Solution {
   public:
    Node* connect(Node* root) {
        Node* leftMostNode = root;
        Node *prev, *curr;

        function<void(Node*)> link = [&](Node* u) -> void {
            if (!u) return;

            prev = curr, curr = u;
            if (prev) {
                prev->next = curr;
            } else {
                leftMostNode = curr;
            }
        };

        while (leftMostNode) {
            auto p = leftMostNode;
            prev = curr = leftMostNode = nullptr;
            while (p) {
                link(p->left);
                link(p->right);
                p = p->next;
            }
        }

        return root;
    }
};
