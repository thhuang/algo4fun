class MyHashSet {
    array<vector<int>, 7919> data_;

    vector<int>::iterator Find(int key) {
        auto& bucket = data_[key % data_.size()];
        return find(bucket.begin(), bucket.end(), key);
    }

   public:
    MyHashSet() {}

    void add(int key) {
        auto& bucket = data_[key % data_.size()];
        if (Find(key) != bucket.end()) return;
        bucket.push_back(key);
    }

    void remove(int key) {
        auto& bucket = data_[key % data_.size()];
        if (auto it = Find(key); it != bucket.end()) {
            bucket.erase(it);
        }
    }

    bool contains(int key) {
        auto& bucket = data_[key % data_.size()];
        return Find(key) != bucket.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
