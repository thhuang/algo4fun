class Solution {
   public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int mx = 0, total = 0;
        for (int v : nums) max(mx, v), total += v;
        if (total % k != 0 || mx > total / k) return false;
        int target = total / k;

        unordered_map<int, bool> cache;
        function<bool(int, int, int, int)> search =
            [&](int i, int sum, int count, int vis) -> bool {
            if (count == k) return true;
            if (sum > target) return false;
            if (auto it = cache.find(vis); it != cache.end()) return it->second;
            if (sum == target) return cache[vis] = search(0, 0, count + 1, vis);
            if (i == nums.size()) return false;

            int mask = 1 << i;
            if ((vis & mask) == 0 &&
                search(i + 1, sum + nums[i], count, vis | mask))
                return true;
            if (search(i + 1, sum, count, vis)) return true;
            return cache[vis] = false;
        };

        return search(0, 0, 0, 0);
    }
};
