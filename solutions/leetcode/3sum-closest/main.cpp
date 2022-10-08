class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int result = 1e8;
        for (int i = 0; i < n; ++i) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int v = nums[i] + nums[l] + nums[r];
                if (abs(target - v) < abs(target - result)) {
                    result = v;
                }
                if (v > target) {
                    --r;
                } else {
                    ++l;
                }
            }
        }

        return result;
    }
};
