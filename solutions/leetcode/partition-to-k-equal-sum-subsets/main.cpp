class Solution {
   public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int mx = 0;
        int total = 0;
        for (int v : nums) {
            mx = max(mx, v);
            total += v;
        }
        if (total % k != 0 || mx > total / k) return false;

        sort(nums.begin(), nums.end(), greater<>());

        unordered_map<int, bool> cache;
        function<bool(int, int, int, int)> search =
            [&](int i, int target, int count, int taken) -> bool {
            if (count == k - 1) return true;
            if (target < 0) return false;

            if (cache.count(taken)) return cache[taken];
            if (target == 0)
                return cache[taken] = search(0, total / k, count + 1, taken);

            if (i == nums.size()) return false;

            int mask = 1 << i;
            if ((taken & mask) == 0 &&
                search(i + 1, target - nums[i], count, taken | mask))
                return true;
            if (search(i + 1, target, count, taken)) return true;

            return cache[taken] = false;
        };

        return search(0, total / k, 0, 0);
    }
};
