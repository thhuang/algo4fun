class Solution {
    const int radix = 10;

   public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        int n = nums.size();
        int mn = *max_element(nums.begin(), nums.end());

        for (int x = 1; x <= mn; x *= radix) {
            vector<int> numsNew(n);
            vector<int> cnt(radix, 0);

            for (int v : nums) {
                ++cnt[v / x % radix];
            }

            for (int i = 1; i < radix; ++i) {
                cnt[i] += cnt[i - 1];
            }

            for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
                numsNew[--cnt[*it / x % radix]] = *it;
            }

            nums = numsNew;
        }

        int result = 0;
        for (int i = 1; i < n; ++i) {
            result = max(result, nums[i] - nums[i - 1]);
        }

        return result;
    }
};
