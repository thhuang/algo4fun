class Solution {
   public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int result = numeric_limits<int>::max();
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            result = min({result, nums[l], nums[m], nums[r]});
            if (nums[l] < nums[m]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return result;
    }
};

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            if (nums[l] <= nums[r]) return nums[l];

            int m = l + (r - l) / 2;
            if (nums[l] <= nums[m]) {
                l = m + 1;
            } else {  // nums[l] > nums[m]
                r = m;
            }
        }
        return numeric_limits<int>::max();
    }
};

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] < nums[r]) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return nums[l];
    }
};
