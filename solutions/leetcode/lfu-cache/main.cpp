class LFUCache {
    // key -> {freq, list iterator}
    unordered_map<int, pair<int, list<pair<int, int>>::iterator>> mp;

    // freq -> list [{key, value}]
    vector<list<pair<int, int>>> freq;

    // capacity
    int n;

    void addFreq(
        unordered_map<int, pair<int, list<pair<int, int>>::iterator>>::iterator
            it) {
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

class LFUCache {
    int n;
    vector<list<pair<int, int>>> freq2kv;  // {k, v}
    unordered_map<int, pair<int, list<pair<int, int>>::iterator>> mp;  // {key, {freq, iterator}}

   public:
    LFUCache(int capacity) : n(capacity) {}

    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;

        int f = it->second.first;
        auto p = it->second.second;
        int v = p->second;

        mp.erase(key);
        freq2kv[f++].erase(p);

        while (freq2kv.size() <= f) freq2kv.push_back({});
        freq2kv[f].push_front({key, v});
        mp[key] = {f, freq2kv[f].begin()};

        return v;
    }

    void put(int key, int value) {
        if (n == 0) return;

        int f = 1;
        if (auto it = mp.find(key); it != mp.end()) {
            f = it->second.first;
            auto p = it->second.second;
            mp.erase(key);
            freq2kv[f++].erase(p);
        }

        if (mp.size() == n) {
            for (int i = 0; i < freq2kv.size(); ++i) {
                if (freq2kv[i].empty()) continue;
                auto [k, _] = freq2kv[i].back();
                freq2kv[i].pop_back();
                mp.erase(k);
                break;
            }
        }

        while (freq2kv.size() <= f) freq2kv.push_back({});
        freq2kv[f].push_front({key, value});
        mp[key] = {f, freq2kv[f].begin()};
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
