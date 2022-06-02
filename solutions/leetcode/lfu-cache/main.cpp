class LFUCache {
    // key -> {freq, list iterator}
    unordered_map<int, pair<int, list<pair<int, int>>::iterator>> mp;

    // freq -> list [{key, value}]
    vector<list<pair<int, int>>> freq;

    // capacity
    int n;

    void addFreq(
        unordered_map<int, pair<int, list<pair<int, int>>::iterator>>::iterator it) {
        int f = it->second.first;
        auto [k, v] = *it->second.second;

        freq[f].erase(it->second.second);

        ++f;
        if (f == freq.size()) freq.push_back({});
        freq[f].push_front({k, v});

        mp[k] = {f, freq[f].begin()};
    }

    void popLeastFreq() {
        for (auto& lst : freq) {
            if (lst.empty()) continue;
            mp.erase(lst.back().first);
            lst.pop_back();
            return;
        }
    }

   public:
    LFUCache(int capacity) : n(capacity), freq(1) {}

    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;

        int value = it->second.second->second;
        addFreq(it);

        return value;
    }

    void put(int key, int value) {
        if (n == 0) return;

        auto it = mp.find(key);
        if (it != mp.end()) {
            it->second.second->second = value;
            addFreq(it);
            return;
        }

        if (mp.size() == n) popLeastFreq();

        freq[0].push_front({key, value});
        mp[key] = {0, freq[0].begin()};
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
