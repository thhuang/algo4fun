class Solution {
   public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int result = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1, k = n - 1; j < k; ++j) {
                while (j < k && nums[i] + nums[j] + nums[k] >= target) --k;
                if (j >= k) break;
                result += k - j;
            }
        }

        return result;
    }
};
