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
    unordered_map<Node*, Node*> mp;

   public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        if (mp.count(node) > 0) {
            return mp[node];
        }

        Node* newNode = mp[node] = new Node(node->val);
        for (auto u : node->neighbors) {
            newNode->neighbors.push_back(cloneGraph(u));
        }

        return newNode;
    }
};
