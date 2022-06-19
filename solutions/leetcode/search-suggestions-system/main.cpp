class Solution {
    struct Node {
        vector<const string*> suggestions;
        array<Node*, 26> children = array<Node*, 26>();
    };

    Node* root = new Node;
    Node* iter = root;

    void insert(const string& s) {
        auto p = root;
        for (char c : s) {
            int i = c - 'a';
            if (p->children[i] == nullptr) p->children[i] = new Node;
            p = p->children[i];
            p->suggestions.push_back(&s);
            if (p->suggestions.size() > 3) {
                sort(p->suggestions.begin(), p->suggestions.end(),
                     [](const string* a, const string* b) -> bool {
                         return *a < *b;
                     });
                p->suggestions.pop_back();
            }
        }
    }

   public:
    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {
        unordered_map<string, int> index;
        for (int i = 0; i < products.size(); ++i) {
            insert(products[i]);
            index.emplace(products[i], i);
        }

        vector<vector<string>> result;
        for (char c : searchWord) {
            result.push_back({});

            if (iter == nullptr) continue;

            int i = c - 'a';
            if (iter->children[i] == nullptr) {
                iter = nullptr;
                continue;
            }

            iter = iter->children[i];
            for (const string* ps : iter->suggestions) {
                result.back().push_back(*ps);
                sort(result.back().begin(), result.back().end());
            }
        }

        return result;
    }
};
