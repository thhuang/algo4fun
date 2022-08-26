class Solution {
   public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        auto check = [&](int divisor) -> bool {
            long long sum = 0;
            for (int v : nums) sum += (v - 1) / divisor + 1;
            return sum <= threshold;
        };

        int l = 1, r = *max_element(nums.begin(), nums.end());
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (check(m)) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return l;
    }
};
