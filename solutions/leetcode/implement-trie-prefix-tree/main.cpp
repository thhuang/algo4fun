class Trie {
    struct Node {
        bool is_end = false;
        unordered_map<char, Node*> children;
    };

    Node* root;

   public:
    Trie() : root(new Node) {}

    void insert(string word) {
        auto p = root;
        for (char c : word) {
            auto q = p->children[c];
            if (!q) q = p->children[c] = new Node;
            p = q;
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

class Trie {
    struct Node {
        Node() : is_end(false), children(array<Node*, 26>()) {}

        bool is_end;
        array<Node*, 26> children;
    };

    Node* root;

    Node* searchWord(const string& word) {
        auto u = root;
        for (char c : word) {
            auto v = u->children[c - 'a'];
            if (!v) return nullptr;
            u = v;
        }
        return u;
    }

   public:
    Trie() : root(new Node()) {}

    void insert(string word) {
        auto u = root;
        for (char c : word) {
            int k = c - 'a';
            if (!u->children[k]) u->children[k] = new Node();
            u = u->children[k];
        }
        u->is_end = true;
    }

    bool search(string word) {
        auto u = searchWord(word);
        return u && u->is_end;
    }

    bool startsWith(string prefix) { return searchWord(prefix); }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
