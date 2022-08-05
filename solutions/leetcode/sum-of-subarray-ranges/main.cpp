class Solution {
   public:
    long long subArrayRanges(vector<int>& nums) {
        long long result = 0;
        for (int l = 0; l < nums.size(); ++l) {
            int mn = numeric_limits<int>::max();
            int mx = numeric_limits<int>::min();

            for (int r = l; r < nums.size(); ++r) {
                mx = max(mx, nums[r]);
                mn = min(mn, nums[r]);
                result += mx - mn;
            }
        }
        return result;
    }
};
