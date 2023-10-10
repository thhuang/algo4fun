class Solution {
   public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int m = unique(nums.begin(), nums.end()) - nums.begin();

        int result = n;
        for (int l = 0, r = 0; r < m; ++r) {
            while (nums[l] < nums[r] - n + 1) ++l;
            result = min(result, n - (r - l + 1));
        }

        return result;
    }
};
