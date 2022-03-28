class Solution {
   public:
    bool search(vector<int>& nums, int target) {
        function<bool(int, int)> range_search = [&](int l, int r) -> bool {
            while (l <= r) {
                int m = l + (r - l) / 2;
                int a = nums[l], b = nums[m], c = nums[r];

                if (a == target || b == target || c == target) return true;
                if (a == b || b == c)
                    return range_search(l, m - 1) || range_search(m + 1, r);

                if (a < b && (target < a || b < target)) {
                    l = m + 1;
                } else if (b < c && (b < target && target < c)) {
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
