/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
   public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> mp;

        function<Node*(Node*)> clone = [&](Node* u) -> Node* {
            if (mp.count(u)) return mp[u];
            auto new_u = mp[u] = new Node(u->val);
            for (Node* v : u->neighbors) new_u->neighbors.push_back(clone(v));
            return new_u;
        };

        return clone(node);
    }
};

class Solution {
    unordered_map<Node*, Node*> mp;

   public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        if (mp.count(node)) return mp[node];
        auto nodeNew = mp[node] = new Node(node->val);
        for (auto u : node->neighbors)
            nodeNew->neighbors.push_back(cloneGraph(u));
        return nodeNew;
    }
};
