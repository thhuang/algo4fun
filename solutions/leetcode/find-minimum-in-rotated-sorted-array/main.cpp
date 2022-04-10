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
