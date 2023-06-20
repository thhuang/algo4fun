class Solution {
   public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n, -1);

        if (n <= k * 2) return result;

        long long sum = accumulate(nums.begin(), nums.begin() + k * 2, 0LL);
        for (int i = k * 2; i < n; ++i) {
            sum += nums[i];
            result[i - k] = sum / (k * 2 + 1);
            sum -= nums[i - k * 2];
        }

        return result;
    }
};
