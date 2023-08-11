class Solution {
   public:
    bool search(vector<int>& nums, int target) {
        function<bool(int, int)> f = [&](int l, int r) -> bool {
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (nums[l] == target || nums[m] == target || nums[r] == target) return true;
                if (nums[l] < nums[m] && (nums[l] < target && target < nums[m])) {
                    r = m - 1;
                } else if (nums[l] > nums[m] && (target < nums[m] || nums[l] < target)) {
                    r = m - 1;
                } else if (nums[l] == nums[m]) {
                    return f(l, m - 1) || f(m + 1, r);
                } else {
                    l = m + 1;
                }
            }
            return false;
        };

        return f(0, nums.size() - 1);
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
