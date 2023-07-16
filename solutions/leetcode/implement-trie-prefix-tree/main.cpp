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
        array<Node*, 26> children;
        bool isEnd = false;

        Node() { children.fill(nullptr); }

        ~Node() {
            for (int i = 0; i < 26; ++i) {
                if (children[i]) delete children[i];
            }
        }
    };

    Node* root;

    Node* find(const string& s) {
        auto curr = root;
        for (char c : s) {
            int i = c - 'a';
            if (curr->children[i] == nullptr) return nullptr;
            curr = curr->children[i];
        }
        return curr;
    }

   public:
    Trie() { root = new Node(); }

    ~Trie() { delete root; }

    void insert(string word) {
        auto curr = root;
        for (char c : word) {
            int i = c - 'a';
            if (curr->children[i] == nullptr) curr->children[i] = new Node();
            curr = curr->children[i];
        }
        curr->isEnd = true;
    }

    bool search(string word) {
        auto result = find(word);
        return result != nullptr && result->isEnd;
    }

    bool startsWith(string prefix) { return find(prefix) != nullptr; }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
