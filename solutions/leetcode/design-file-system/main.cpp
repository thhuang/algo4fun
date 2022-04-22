class FileSystem {
    regex dir_regex_ = regex("/[a-z]+");
    regex path_regex_ = regex("(/[a-z]+)+");
    unordered_map<string, int> data_;

   public:
    FileSystem() {}

    bool createPath(string path, int value) {
        if (!regex_match(path, path_regex_)) return false;
        if (data_.count(path)) return false;

        auto it = sregex_iterator(path.begin(), path.end(), dir_regex_);
        auto it_end = sregex_iterator();
        int length = distance(it, it_end);
        string dir;
        while (--length) {
            dir += (it++)->str();
            if (data_.count(dir) == 0) return false;
        }

        data_[path] = value;
        return true;
    }

    int get(string path) {
        if (!regex_match(path, path_regex_)) return -1;
        if (auto it = data_.find(path); it != data_.end()) {
            return it->second;
        } else {
            return -1;
        }
    }
};

class FileSystem {
    struct TrieNode {
        string key;
        int val;
        unordered_map<string, TrieNode*> children;

        TrieNode(string key, int val) : key(key), val(val), children() {}
    };

    TrieNode* root_;
    regex path_regex_ = regex("/[a-z]+");

   public:
    FileSystem() : root_(new TrieNode("", 0)) {}

    bool createPath(string path, int value) {
        if (path.empty() || path.size() == 1 || path.front() != '/' ||
            path.back() == '/')
            return false;

        auto p = root_;
        auto it = sregex_iterator(path.begin(), path.end(), path_regex_);
        auto it_end = sregex_iterator();
        int dist = distance(it, it_end);
        for (int i = 1; i < dist; ++i) {
            auto got = p->children.find(it->str());
            if (got == p->children.end()) return false;
            p = got->second, ++it;
        }

        if (p->children.count(it->str())) return false;
        p->children.insert({it->str(), new TrieNode(it->str(), value)});

        return true;
    }

    int get(string path) {
        auto p = root_;
        for (auto it = sregex_iterator(path.begin(), path.end(), path_regex_);
             it != sregex_iterator(); ++it) {
            auto got = p->children.find(it->str());
            if (got == p->children.end()) return -1;
            p = got->second;
        }
        return p->val;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
