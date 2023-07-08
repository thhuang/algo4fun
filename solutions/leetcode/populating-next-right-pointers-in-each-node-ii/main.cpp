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
    array<Node*, 2> process_child(Node* prev_child, Node* curr_child,
                                  Node* left_most_node) {
        if (!curr_child) return {prev_child, left_most_node};
        if (prev_child) {
            prev_child->next = curr_child;
        } else {
            left_most_node = curr_child;
        }
        return {curr_child, left_most_node};
    }

    Node* connect(Node* root) {
        auto left_most_node = root;

        while (left_most_node) {
            Node* p = left_most_node;
            Node* prev_child = nullptr;
            left_most_node = nullptr;

            while (p) {
                array<Node*, 2> res;
                res = process_child(prev_child, p->left, left_most_node);
                prev_child = res[0], left_most_node = res[1];
                res = process_child(prev_child, p->right, left_most_node);
                prev_child = res[0], left_most_node = res[1];
                p = p->next;
            }
        }

        return root;
    }
};

class Solution {
   public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;

        Node* left_most_node = nullptr;
        Node* p = root;
        Node* prev = nullptr;
        Node* curr = nullptr;

        auto link = [&](Node* node) -> void {
            if (node == nullptr) return;

            prev = curr;
            curr = node;

            if (prev == nullptr) {
                left_most_node = node;
                return;
            }

            prev->next = curr;
        };

        while (p) {
            link(p->left);
            link(p->right);
            p = p->next;
        }

        connect(left_most_node);

        return root;
    }
};

class Solution {
   public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;

        Node* left_most_node = root;
        Node* prev;
        Node* curr;

        auto link = [&prev, &curr, &left_most_node](Node* node) -> void {
            if (node == nullptr) return;

            prev = curr;
            curr = node;

            if (prev == nullptr) {
                left_most_node = node;
                return;
            }

            prev->next = curr;
        };

        while (left_most_node) {
            Node* p = left_most_node;
            prev = curr = left_most_node = nullptr;
            while (p) {
                link(p->left);
                link(p->right);
                p = p->next;
            }
        }

        return root;
    }
};
