class FileSystem {
    struct Node {
        unordered_map<string, Node*> children;
        string content = "";
        bool is_file = false;
    };

    Node* root = new Node;

    tuple<Node*, string> search(string& path) {
        if (path.empty()) path.push_back('/');
        stringstream ss(path);
        string s;
        getline(ss, s, '/');

        auto p = root;
        while (getline(ss, s, '/')) p = p->children[s];

        return {p, s};
    }

    tuple<Node*, string> create(string& path) {
        if (path.empty()) path.push_back('/');
        stringstream ss(path);
        string s;
        getline(ss, s, '/');

        auto p = root;
        while (getline(ss, s, '/')) {
            auto it = p->children.find(s);
            if (it == p->children.end()) {
                p->children[s] = new Node;
                it = p->children.find(s);
            }
            p = it->second;
        }

        return {p, s};
    }

   public:
    vector<string> ls(string path) {
        auto [p, s] = search(path);

        if (p->is_file) return {s};

        vector<string> result;
        for (const auto& [name, _] : p->children) result.push_back(name);
        sort(result.begin(), result.end());

        return result;
    }

    void mkdir(string path) { create(path); }

    void addContentToFile(string filePath, string content) {
        auto [p, _] = create(filePath);
        p->is_file = true;
        p->content += content;
    }

    string readContentFromFile(string filePath) {
        auto [p, _] = search(filePath);
        return p->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
