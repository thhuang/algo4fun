class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        int l = 1, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m - 1] < nums[m]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return r;
    }
};

class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int a = nums[m];
            int b = m + 1 < nums.size() ? nums[m + 1] : numeric_limits<int>::min();
            if (a < b) {
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
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 2;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] < nums[m + 1]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l;
    }
};
