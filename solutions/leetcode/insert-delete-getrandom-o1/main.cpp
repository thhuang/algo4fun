class RandomizedSet {
    vector<int> vals;
    unordered_map<int, int> mp;

   public:
    bool insert(int val) {
        if (mp.count(val) > 0) return false;
        mp[val] = vals.size();
        vals.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (mp.count(val) == 0) return false;
        int v = vals.back();

        swap(mp[val], mp[v]);
        swap(vals[mp[val]], vals[mp[v]]);

        mp.erase(val);
        vals.pop_back();

        return true;
    }

    int getRandom() {
        int n = vals.size();
        int offset = numeric_limits<int>::max() % n;
        int i = random();
        while (i < offset) i = random();
        return vals[i % n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
