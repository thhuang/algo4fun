class Trie {
    struct Node {
        array<Node*, 26> children = {};
        int equalTo = 0;
        int startingWith = 0;
    };

    Node* root;

   public:
    Trie() { root = new Node; }

    void insert(string word) {
        Node* p = root;
        for (char c : word) {
            int i = c - 'a';
            if (p->children[i] == nullptr) {
                p->children[i] = new Node;
            }
            p = p->children[i];
            ++p->startingWith;
        }
        ++p->equalTo;
    }

    int countWordsEqualTo(string word) {
        Node* p = root;
        for (char c : word) {
            int i = c - 'a';
            if (p->children[i] == nullptr) {
                return 0;
            }
            p = p->children[i];
        }
        return p->equalTo;
    }

    int countWordsStartingWith(string prefix) {
        Node* p = root;
        for (char c : prefix) {
            int i = c - 'a';
            if (p->children[i] == nullptr) {
                return 0;
            }
            p = p->children[i];
        }
        return p->startingWith;
    }

    void erase(string word) {
        Node* p = root;
        for (char c : word) {
            int i = c - 'a';
            p = p->children[i];
            --p->startingWith;
        }
        --p->equalTo;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */
