class WordDictionary {
    struct Node {
        char c;
        bool is_end;
        unordered_map<char, Node*> children;
    };

    Node* root;

   public:
    WordDictionary() : root(new Node) {}

    void addWord(string word) {
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

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
