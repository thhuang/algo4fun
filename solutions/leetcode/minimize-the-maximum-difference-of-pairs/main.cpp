class Solution {
   public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        auto check = [&](int v) -> bool {
            int cnt = 0;
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i] - nums[i - 1] <= v) ++cnt, ++i;
            }
            return cnt >= p;
        };

        int l = 0, r = nums.back() - nums.front();
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
