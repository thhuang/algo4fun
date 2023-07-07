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

class LRUCache {
    int cap;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    list<pair<int, int>> data;  // {key, value}

   public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        if (mp.count(key) == 0) return -1;

        auto it = mp.find(key)->second;
        int value = it->second;

        data.erase(it);
        data.push_front({key, value});
        mp[key] = data.begin();

        return value;
    }

    void put(int key, int value) {
        if (auto it = mp.find(key); it != mp.end()) {
            data.erase(it->second);
        }

        data.push_front({key, value});
        mp[key] = data.begin();

        if (data.size() > cap) {
            auto [k, _] = data.back();
            data.pop_back();
            mp.erase(k);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
