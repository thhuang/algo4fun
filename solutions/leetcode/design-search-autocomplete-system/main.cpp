class AutocompleteSystem {
    struct Node {
        unordered_set<string> sentences;
        unordered_map<char, Node*> children;
    };

    void insert(const string& s) {
        auto p = root;
        for (char c : s) {
            auto it = p->children.find(c);
            if (it == p->children.end()) {
                p->children[c] = new Node;
                it = p->children.find(c);
            }
            p = it->second;
            p->sentences.insert(s);
        }
    }

    Node* root = new Node;
    Node* iter = root;
    string curr;
    unordered_map<string, int> sentence_freq;

   public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        for (int i = 0; i < sentences.size(); ++i) {
            insert(sentences[i]);
            sentence_freq[sentences[i]] = times[i];
        }
    }

    vector<string> input(char c) {
        if (c == '#') {
            insert(curr);
            ++sentence_freq[curr];

            curr = "";
            iter = root;

            return {};
        }

        curr += c;
        if (!iter) return {};

        auto it = iter->children.find(c);
        if (it == iter->children.end()) {
            iter = nullptr;
            return {};
        }

        iter = it->second;
        vector<string> result(iter->sentences.begin(), iter->sentences.end());
        sort(result.begin(), result.end(),
             [&](const string& a, const string& b) -> bool {
                 int fa = sentence_freq[a];
                 int fb = sentence_freq[b];
                 if (fa == fb) return a < b;
                 return fa > fb;
             });

        if (result.size() < 3) return result;
        return {result.begin(), result.begin() + 3};
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
