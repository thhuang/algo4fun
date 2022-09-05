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
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};

        vector<vector<int>> result;
        queue<tuple<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto [u, lv] = q.front();
            q.pop();

            if (result.size() == lv) result.push_back({});
            result[lv].push_back(u->val);

            for (Node* v : u->children) q.push({v, lv + 1});
        }

        return result;
    }
};
