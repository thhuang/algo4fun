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
        array<Node*, 26> children = {};
        bool isEnd = false;
    };

    Node* root = new Node;

    Node* searchNode(string s) {
        Node* p = root;
        for (char c : s) {
            int i = c - 'a';
            if (p->children[i] == nullptr) return nullptr;
            p = p->children[i];
        }
        return p;
    }

   public:
    void insert(string word) {
        Node* p = root;
        for (char c : word) {
            int i = c - 'a';
            if (p->children[i] == nullptr) p->children[i] = new Node;
            p = p->children[i];
        }
        p->isEnd = true;
    }

    bool search(string word) {
        auto u = searchNode(word);
        return u != nullptr && u->isEnd;
    }

    bool startsWith(string prefix) { return searchNode(prefix) != nullptr; }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
