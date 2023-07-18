class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int result = *max_element(nums.begin(), nums.end());

        for (int l = 0, r = 0, v = 0; r < nums.size(); ++r) {
            v += nums[r];

            if (v < 0) {
                l = r + 1;
                v = 0;
            } else {
                result = max(result, v);
            }
        }

        return result;
    }
};

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int result = numeric_limits<int>::min();
        int curr = 0;
        for (int v : nums) {
            curr = max(curr, 0) + v;
            result = max(result, curr);
        }
        return result;
    }
};
