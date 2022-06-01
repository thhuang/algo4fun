class Trie {
    struct Node {
        char c;
        bool is_end;
        unordered_map<char, Node*> children;
    };

    Node* root;

   public:
    Trie() : root(new Node) {}

    void insert(string word) {
        auto p = root;
        for (char c : word) {
            if (p->children.count(c) == 0) {
                p->children[c] = new Node{c, false, {}};
            }
            p = p->children[c];
        }
        p->is_end = true;
    }

    bool search(string word) {
        auto p = root;
        for (char c : word) {
            auto it = p->children.find(c);
            if (it == p->children.end()) return false;
            p = it->second;
        }
        return p->is_end;
    }

    bool startsWith(string prefix) {
        auto p = root;
        for (char c : prefix) {
            auto it = p->children.find(c);
            if (it == p->children.end()) return false;
            p = it->second;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
