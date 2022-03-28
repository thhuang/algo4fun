class Solution {
   public:
    bool search(vector<int>& nums, int target) {
        function<bool(int, int)> range_search = [&](int l, int r) -> bool {
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (target == nums[l] || target == nums[m] || target == nums[r])
                    return true;
                if (nums[l] == nums[m] || nums[m] == nums[r])
                    return range_search(l, m - 1) || range_search(m + 1, r);

                if (nums[l] < nums[m] &&
                    (target < nums[l] || nums[m] < target)) {
                    l = m + 1;
                } else if (nums[m] < nums[r] &&
                           (nums[m] < target && target < nums[r])) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }

            return false;
        };

        return range_search(0, size(nums) - 1);
    }
};
