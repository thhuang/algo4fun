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

class Solution {
   public:
    bool search(vector<int>& nums, int target) {
        vector<array<int, 2>> vec = {{0, int(size(nums) - 1)}};
        while (!empty(vec)) {
            auto [l, r] = vec.back();
            vec.pop_back();
            if (l > r) continue;

            int m = l + (r - l) / 2;
            if (target == nums[l] || target == nums[m] || target == nums[r])
                return true;
            if (nums[l] == nums[m] || nums[m] == nums[r]) {
                vec.push_back({l, m - 1});
                vec.push_back({m + 1, r});
                continue;
            }

            if (nums[l] < nums[m] && (target < nums[l] || nums[m] < target)) {
                vec.push_back({m + 1, r});
            } else if (nums[m] < nums[r] &&
                       (nums[m] < target && target < nums[r])) {
                vec.push_back({m + 1, r});
            } else {
                vec.push_back({l, m - 1});
            }
        }

        return false;
    }
};
