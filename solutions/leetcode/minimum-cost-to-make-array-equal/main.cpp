class Solution {
   public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());

        auto cal = [&](int t) -> long long {
            long long result = 0;
            for (int i = 0; i < n; ++i) {
                result += abs((long long)(nums[i] - t) * cost[i]);
            }
            return result;
        };

        while (l < r) {
            int m = l + (r - l) / 2;
            long long c1 = cal(m);
            long long c2 = cal(m + 1);
            if (c1 < c2) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return min(cal(l), cal(r));
    }
};
