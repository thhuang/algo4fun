class Solution {
    struct Node {
        array<Node*, 26> children = array<Node*, 26>();
        bool is_leaf = true;
    };

    Node* root = new Node;

    void insert(const string& s) {
        auto p = root;
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            p->is_leaf = false;
            int i = *it - 'a';
            if (p->children[i] == nullptr) p->children[i] = new Node;
            p = p->children[i];
        }
    }

   public:
    int minimumLengthEncoding(vector<string>& words) {
        for (const string& s : words) insert(s);

        int result = 0;
        function<void(Node*, int)> dfs = [&](Node* u, int d) -> void {
            if (u->is_leaf) {
                result += d;
                return;
            }

            ++d;
            for (auto v : u->children) {
                if (v) dfs(v, d);
            }
        };

        dfs(root, 1);

        return result;
    }
};
