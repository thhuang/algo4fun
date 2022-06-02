class Solution {
    struct Node {
        bool is_end = false;
        unordered_map<char, Node*> children;
    };

    Node* root = new Node;

    void put(const string& s) {
        auto p = root;
        for (char c : s) {
            auto it = p->children.find(c);
            if (it == p->children.end()) {
                p->children[c] = new Node;
                it = p->children.find(c);
            }
            p = it->second;
        }
        p->is_end = true;
    }

   public:
    string longestWord(vector<string>& words) {
        for (const auto& s : words) put(s);

        string result, s;
        function<void(Node*)> search = [&](Node* u) -> void {
            if (s.size() == result.size() && s < result) result = s;
            if (s.size() > result.size()) result = s;

            for (const auto [c, v] : u->children) {
                if (!v->is_end) continue;
                s.push_back(c);
                search(v);
                s.pop_back();
            }
        };

        search(root);

        return result;
    }
};
