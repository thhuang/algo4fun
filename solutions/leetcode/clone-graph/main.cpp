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
        unordered_map<Node*, Node*> mp;

        function<Node*(Node*)> clone = [&](Node* u) -> Node* {
            if (u == nullptr) return nullptr;
            if (auto it = mp.find(u); it != mp.end()) return it->second;

            mp[u] = new Node(u->val);
            for (Node* v : u->neighbors) {
                mp[u]->neighbors.push_back(clone(v));
            }
            return mp[u];
        };

        return clone(node);
    }
};
