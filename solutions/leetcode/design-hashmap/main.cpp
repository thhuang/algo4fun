class MyHashMap {
    static const int n_ = 6997;
    vector<deque<pair<int, int>>> data_;

   public:
    MyHashMap() : data_(vector<deque<pair<int, int>>>(n_)) {}

    void put(int key, int value) {
        remove(key);
        data_[key % n_].push_back({key, value});
    }

    int get(int key) {
        auto& v = data_[key % n_];
        for (auto it = v.begin(); it != v.end(); ++it) {
            if (it->first == key) return it->second;
        }
        return -1;
    }

    void remove(int key) {
        auto& v = data_[key % n_];
        for (auto it = v.begin(); it != v.end(); ++it) {
            if (it->first == key) {
                v.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
