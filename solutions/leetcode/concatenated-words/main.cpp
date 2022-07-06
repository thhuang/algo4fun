class Solution {
    struct Node {
        array<Node*, 26> children = array<Node*, 26>();
        bool is_end = false;
    };

    Node* root = new Node;

    void insert(const string& s) {
        auto p = root;
        for (char c : s) {
            int i = c - 'a';
            if (!p->children[i]) p->children[i] = new Node;
            p = p->children[i];
        }
        p->is_end = true;
    }

   public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for (const string& w : words) insert(w);

        function<bool(const string&, int, Node*, bool)> dfs =
            [&](const string& s, int i, Node* p, bool is_candidate) -> bool {
            if (i == s.size()) return p->is_end && is_candidate;

            auto q = p->children[s[i] - 'a'];
            if (!q) return false;

            if (q->is_end && dfs(s, i + 1, root, true)) return true;
            return dfs(s, i + 1, q, is_candidate);
        };

        vector<string> result;
        for (const string& w : words) {
            if (dfs(w, 0, root, false)) result.push_back(w);
        }

        return result;
    }
};
