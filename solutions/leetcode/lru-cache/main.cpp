class LRUCache {
    int n;
    list<pair<int, int>> order;                             // {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> mp;  // {key, iter}

   public:
    LRUCache(int capacity) : n(capacity) {}

    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;

        int value = it->second->second;
        order.erase(it->second);

        order.push_front({key, value});
        mp[key] = order.begin();

        return value;
    }

    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()) order.erase(it->second);

        order.push_front({key, value});
        mp[key] = order.begin();

        if (order.size() <= n) return;

        mp.erase(order.back().first);
        order.pop_back();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
