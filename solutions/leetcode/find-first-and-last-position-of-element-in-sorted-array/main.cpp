class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto search_first = [&]() -> int {
            int l = 0, r = nums.size() - 1;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (nums[m] < target) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            return l;
        };

        auto search_last = [&]() -> int {
            int l = 0, r = nums.size() - 1;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (nums[m] <= target) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            return l;
        };

        int l = search_first();
        int r = search_last();
        if (l == r) return {-1, -1};
        return {l, r - 1};
    }
};

class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        function<int(int)> search = [&](int x) -> int {
            int l = 0, r = nums.size() - 1;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (nums[m] < x) {
                    l = m + 1;
                } else {  // nums[m] >= x
                    r = m - 1;
                }
            }
            return l;
        };

        int l = search(target);
        int r = search(target + 1);
        if (l == r) return {-1, -1};
        return {l, r - 1};
    }
};

class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto search = [&](function<bool(int)> cmp) -> int {
            int l = 0, r = nums.size() - 1;
            while (l <= r) {
                int m = l + (r - l) / 2;
                cmp(nums[m]) ? l = m + 1 : r = m - 1;
            }
            return l;
        };

        int l = search([&](int v) -> bool { return v < target; });
        int r = search([&](int v) -> bool { return v <= target; });

        if (l == r) return {-1, -1};
        return {l, r - 1};
    }
};
