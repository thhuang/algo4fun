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

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
