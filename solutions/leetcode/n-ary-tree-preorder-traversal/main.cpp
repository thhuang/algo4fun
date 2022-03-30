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
    vector<int> preorder(Node* root) {
        vector<int> ans;

        function<void(Node*)> search = [&](Node* u) -> void {
            if (u == nullptr) return;
            ans.push_back(u->val);
            for (auto v : u->children) search(v);
        };

        search(root);
        return ans;
    }
};
