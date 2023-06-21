class Solution {
   public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        function<long long(int)> calc = [&](int t) -> long long {
            long long result = 0;
            for (int i = 0; i < nums.size(); ++i) {
                result += (long long)abs(nums[i] - t) * cost[i];
            }
            return result;
        };

        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());
        while (l <= r) {
            int m = l + (r - l) / 2;
            long long a = calc(m - 1);
            long long b = calc(m);
            if (a > b) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return calc(r);
    }
};
