class Solution {
   public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        auto check = [&](int d) -> bool {
            int count = 0;
            for (int l = 0, r = 1; r < n; ++r) {
                while (l < r && nums[r] - nums[l] >= d) ++l;
                count += r - l;
            }
            return count < k;
        };

        int l = 0, r = nums.back() - nums.front();
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (check(m)) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return r;
    }
};
