class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) return m;
            if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return -1;
    }
};

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (nums[m] <= target) {
                l = m;
            } else {
                r = m;
            }
        }
        if (nums[l] == target) return l;
        return -1;
    }
};
