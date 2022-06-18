class WordFilter {
    const char dilimiter = ':';

    struct Node {
        array<Node*, 27> children = array<Node*, 27>();
        int index = -1;
    };

    Node* root = new Node;

    int char2idx(char c) { return c == dilimiter ? 26 : c - 'a'; }

    void insert(const string_view& s, int index) {
        auto p = root;
        for (char c : s) {
            int i = char2idx(c);
            if (p->children[i] == nullptr) p->children[i] = new Node;
            p = p->children[i];
        }
        p->index = index;
    };

    Node* search(const string_view& s) {
        auto p = root;
        for (char c : s) {
            int i = char2idx(c);
            if (p->children[i] == nullptr) return nullptr;
            p = p->children[i];
        }
        return p;
    }

   public:
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            const string& w = words[i];
            string s = w + dilimiter + w;
            string_view sv(s);
            for (int j = 0; j < w.size(); ++j) {
                insert(sv, i);
                sv.remove_prefix(1);
            }
        }
    }

    int f(string prefix, string suffix) {
        string s = suffix + dilimiter + prefix;
        string_view sv(s);

        Node* p = search(sv);
        if (p == nullptr) return -1;

        vector<Node*> vec = {p};
        int result = -1;
        while (!vec.empty()) {
            Node* u = vec.back();
            vec.pop_back();

            result = max(result, u->index);
            for (auto v : u->children) {
                if (v) vec.push_back(v);
            }
        }

        return result;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
