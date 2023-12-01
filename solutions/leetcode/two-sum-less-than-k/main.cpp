class Solution {
   public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int result = -1;
        sort(nums.begin(), nums.end());
        for (int l = 0, r = nums.size() - 1; l < r; ++l) {
            while (l < r && nums[l] + nums[r] >= k) --r;
            if (l == r) break;
            result = max(result, nums[l] + nums[r]);
        }
        return result;
    }
};

class Solution {
   public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int result = -1;
        for (int l = 0, r = nums.size() - 1; l < r;) {
            int v = nums[l] + nums[r];
            if (v >= k) {
                --r;
            } else {
                result = max(result, v);
                ++l;
            }
        }
        return result;
    }
};
