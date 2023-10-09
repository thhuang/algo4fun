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

class Solution {
    int findFirstPosition(const vector<int>& nums, int target) {
        int l = -1, r = nums.size() - 1;
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (nums[m] < target) {
                l = m;
            } else {
                r = m;
            }
        }
        if (nums[r] != target) return -1;
        return r;
    }

    int findLastPosition(const vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (nums[m] <= target) {
                l = m;
            } else {
                r = m;
            }
        }
        if (nums[l] != target) return -1;
        return l;
    }

   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        return {findFirstPosition(nums, target),
                findLastPosition(nums, target)};
    }
};

class Solution {
    int firstPosition(vector<int>& nums, int target) {
        int l = -1, r = nums.size();
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (target <= nums[m]) {
                r = m;
            } else {
                l = m;
            }
        }
        if (r == nums.size() || nums[r] != target) return -1;
        return r;
    }

    int lastPosition(vector<int>& nums, int target) {
        int l = -1, r = nums.size();
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (target < nums[m]) {
                r = m;
            } else {
                l = m;
            }
        }
        if (l < 0 || nums[l] != target) return -1;
        return l;
    }

   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        return {firstPosition(nums, target), lastPosition(nums, target)};
    }
};
