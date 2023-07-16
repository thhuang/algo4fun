class WordDictionary {
    struct Node {
        bool is_end = false;
        unordered_map<char, Node*> children;
    };

    Node* root;

   public:
    WordDictionary() : root(new Node) {}

    void addWord(string word) {
        auto p = root;
        for (char c : word) {
            if (p->children.count(c) == 0) {
                p->children[c] = new Node;
            }
            p = p->children[c];
        }
        p->is_end = true;
    }

    bool search(string word) {
        function<bool(int, Node*)> searchSuffix = [&](int i, Node* p) -> bool {
            for (; i < word.size(); ++i) {
                char c = word[i];
                if (c == '.') {
                    for (auto it = p->children.begin(); it != p->children.end();
                         ++it) {
                        if (searchSuffix(i + 1, it->second)) return true;
                    }
                    return false;
                }

                auto it = p->children.find(c);
                if (it == p->children.end()) return false;
                p = it->second;
            }
            return p->is_end;
        };
        return searchSuffix(0, root);
    }
};

class WordDictionary {
    struct Node {
        array<Node*, 26> children;
        bool isEnd = false;

        Node() { children.fill(nullptr); }

        ~Node() {
            for (int i = 0; i < 26; ++i) {
                if (children[i] != nullptr) delete children[i];
            }
        }
    };

    Node* root;

   public:
    WordDictionary() { root = new Node(); }

    ~WordDictionary() { delete root; }

    void addWord(string word) {
        auto curr = root;
        for (char c : word) {
            int i = c - 'a';
            if (curr->children[i] == nullptr) curr->children[i] = new Node();
            curr = curr->children[i];
        }
        curr->isEnd = true;
    }

    bool search(string word) {
        auto curr = root;
        for (int k = 0; k < word.size(); ++k) {
            char c = word[k];

            if (c == '.') {
                string newWord = word;
                for (char cc = 'a'; cc <= 'z'; ++cc) {
                    newWord[k] = cc;
                    if (search(newWord)) return true;
                }
                return false;
            }

            int i = c - 'a';
            if (curr->children[i] == nullptr) return false;
            curr = curr->children[i];
        }
        return curr->isEnd;
    }
};

class WordDictionary {
    struct Node {
        Node() : is_end(false), children(array<Node*, 26>()) {}

        bool is_end;
        array<Node*, 26> children;
    };

    int idx(char c) { return c - 'a'; }

    bool check(string& word, int i, Node* p) {
        for (; i < word.size(); ++i) {
            if (word[i] == '.') {
                for (auto n : p->children) {
                    if (!n) continue;
                    if (check(word, i + 1, n)) return true;
                }
                return false;
            }

            int k = idx(word[i]);
            if (!p->children[k]) return false;
            p = p->children[k];
        }
        return p->is_end;
    };

    Node* root;

   public:
    WordDictionary() : root(new Node()) {}

    void addWord(string word) {
        auto p = root;
        for (char c : word) {
            int k = idx(c);
            if (!p->children[k]) p->children[k] = new Node();
            p = p->children[k];
        }
        p->is_end = true;
    }

    bool search(string word) { return check(word, 0, root); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
