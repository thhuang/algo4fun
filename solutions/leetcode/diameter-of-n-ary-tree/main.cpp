/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
   public:
    int diameter(Node* root) {
        int result = 0;

        function<int(Node*)> dfs = [&](Node* u) -> int {
            if (u->children.empty()) return 1;
            multiset<int> t;
            for (Node* v : u->children) {
                t.insert(dfs(v));
                if (t.size() > 2) t.erase(t.begin());
            }

            if (t.size() == 1) {
                result = max(result, *t.rbegin());
            } else {
                result = max(result, *t.begin() + *t.rbegin());
            }
            return *t.rbegin() + 1;
        };

        dfs(root);

        return result;
    }
};

class Solution {
   public:
    int diameter(Node* root) {
        int result = 0;

        function<int(Node*)> dfs = [&](Node* u) -> int {
            if (u->children.empty()) return 1;

            priority_queue<int> q;
            for (Node* v : u->children) q.push(dfs(v));

            int v = q.top();
            q.pop();
            if (q.empty()) {
                result = max(result, v);
            } else {
                result = max(result, v + q.top());
            }

            return v + 1;
        };

        dfs(root);

        return result;
    }
};

class Solution {
   public:
    int diameter(Node* root) {
        int result = 0;

        function<int(Node*)> dfs = [&](Node* u) -> int {
            if (u->children.empty()) return 1;

            int d0 = 0, d1 = 0;
            for (Node* v : u->children) {
                int d = dfs(v);
                if (!d0) {
                    d0 = d;
                } else if (d > d1) {
                    d1 = d;
                }
                if (d0 < d1) swap(d0, d1);
            }

            result = max(result, d0 + d1);

            return d0 + 1;
        };

        dfs(root);

        return result;
    }
};

class Solution {
   public:
    int diameter(Node* root) {
        int result = 0;

        function<int(Node*)> dfs = [&](Node* u) -> int {
            int max_depth = 0;
            for (Node* v : u->children) {
                int d = dfs(v);
                result = max(result, max_depth + d);
                max_depth = max(max_depth, d);
            }
            return max_depth + 1;
        };

        dfs(root);

        return result;
    }
};
