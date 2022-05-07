class Solution {
   public:
    int missingElement(vector<int>& nums, int k) {
        int missing = 0;
        for (int i = 1; i < nums.size(); ++i) {
            missing += nums[i] - nums[i - 1] - 1;
            if (missing >= k) return nums[i] - 1 - (missing - k);
        }
        return nums.back() + k - missing;
    }
};

class Solution {
   public:
    int missingElement(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int missing = nums[m] - nums.front() - m;
            if (missing < k) {
                l = m + 1;
            } else {  // missing >= k
                r = m - 1;
            }
        }

        --l;
        int missing = nums[l] - nums.front() - l;
        return nums[l] + k - missing;
    }
};
