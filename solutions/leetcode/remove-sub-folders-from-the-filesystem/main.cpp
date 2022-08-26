class Solution {
    struct Node {
        unordered_map<string, Node*> children;
        bool leaf = false;
    };

    Node* root = new Node;

    void add(string folder) {
        vector<string> path;
        stringstream ss(folder);

        Node* p = root;

        string s;
        getline(ss, s, '/');
        while (getline(ss, s, '/')) {
            auto it = p->children.find(s);
            if (it == p->children.end()) {
                p->children[s] = new Node;
                it = p->children.find(s);
            }
            p = it->second;
            if (p->leaf) break;
        }
        p->leaf = true;
        p->children.clear();
    }

   public:
    vector<string> removeSubfolders(vector<string>& folder) {
        for (const string f : folder) add(f);

        vector<string> result;
        vector<string> curr;
        function<void(Node*)> dfs = [&](Node* u) -> void {
            if (u->leaf) {
                result.push_back("");
                for (const string& s : curr) result.back() += "/" + s;
                return;
            }

            for (const auto [s, v] : u->children) {
                curr.push_back(s);
                dfs(v);
                curr.pop_back();
            }
        };

        dfs(root);

        return result;
    }
};
