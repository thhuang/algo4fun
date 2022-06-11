class Solution {
   public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long result = 0;

        long long s = 0;
        int l = 0;
        for (int r = 0; r < n; ++r) {
            s += nums[r];
            if (s * (r - l + 1) < k) continue;

            while (l <= r && s * (r - l + 1) >= k) {
                result += r - l;
                s -= nums[l++];
            }
        }

        long long d = n - l;
        result += d * (d + 1) / 2;

        return result;
    }
};
