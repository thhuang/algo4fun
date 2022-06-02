class Solution {
   public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> nums = {0, 1};
        for (int i = 1; i < n; ++i) {
            int m = nums.size();
            for (int j = 0; j < m; ++j) nums[j] <<= 1;
            for (int j = 0; j < m; ++j) nums.push_back(nums[m - 1 - j] + 1);
        }
        rotate(nums.begin(), find(nums.begin(), nums.end(), start), nums.end());
        return nums;
    }
};
