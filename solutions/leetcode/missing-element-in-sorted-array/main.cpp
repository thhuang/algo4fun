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
        auto missing = [&](int i) -> int { return nums[i] - nums[0] - i; };

        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (missing(m) < k) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return nums[r] + k - missing(r);
    }
};
