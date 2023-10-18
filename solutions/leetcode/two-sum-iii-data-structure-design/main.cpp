class TwoSum {
    unordered_map<int, int> nums;
    unordered_map<int, bool> cache;

   public:
    void add(int number) { ++nums[number]; }

    bool find(int value) {
        if (cache[value]) return cache[value];

        unordered_set<long long> want;
        for (auto [v, cnt] : nums) {
            if (want.count(v)) return cache[value] = true;
            if (cnt > 1 && value == v * 2) return cache[value] = true;
            want.insert((long long)value - v);
        }

        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
