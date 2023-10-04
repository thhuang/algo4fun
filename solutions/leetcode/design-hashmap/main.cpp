class MyHashMap {
    static const size_t sz = 7919;
    array<list<pair<int, int>>, sz> data = {};

   public:
    void put(int key, int value) {
        int i = key % sz;
        for (auto& [k, v] : data[i]) {
            if (k == key) {
                v = value;
                return;
            }
        }
        data[i].push_back({key, value});
    }

    int get(int key) {
        int i = key % sz;
        for (auto& [k, v] : data[i]) {
            if (k == key) {
                return v;
            }
        }
        return -1;
    }

    void remove(int key) {
        int i = key % sz;
        for (auto it = data[i].begin(); it != data[i].end(); ++it) {
            if (it->first == key) {
                data[i].erase(it);
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
