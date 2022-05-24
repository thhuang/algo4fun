class LRUCache {
    list<array<int, 2>> kv;
    unordered_map<int, list<array<int, 2>>::iterator> kp;
    int n;

   public:
    LRUCache(int capacity) : n(capacity) {}

    int get(int key) {
        auto it = kp.find(key);
        if (it == kp.end()) return -1;

        int value = it->second->at(1);
        kv.erase(it->second);

        kv.push_front({key, value});
        kp[key] = kv.begin();

        return value;
    }

    void put(int key, int value) {
        auto it = kp.find(key);
        if (it != kp.end()) kv.erase(it->second);

        kv.push_front({key, value});
        kp[key] = kv.begin();

        if (kv.size() > n) {
            kp.erase(kv.back()[0]);
            kv.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
