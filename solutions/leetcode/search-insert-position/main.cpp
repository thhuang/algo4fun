class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = size(nums) - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] < target) {
                l = m + 1;
                continue;
            }
            if (nums[m] > target) {
                r = m - 1;
                continue;
            }
            return m;
        }
        return l;
    }
};

class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        if (l > 0 && nums[l - 1] == target) return l - 1;
        return l;
    }
};

class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
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
    }
};

class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
