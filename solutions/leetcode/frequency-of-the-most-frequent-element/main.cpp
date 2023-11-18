class Solution {
   public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int result = 0;
        long long sum = 0;
        for (int l = 0, r = 0; r < n; ++r) {
            sum += nums[r];
            while ((long long)nums[r] * (r - l + 1) - sum > k) {
                sum -= nums[l++];
            }
            result = max(result, r - l + 1);
        }

        return result;
    }
};
