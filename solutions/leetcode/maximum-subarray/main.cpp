class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int result = *max_element(nums.begin(), nums.end());

        int sum = 0;
        for (int v : nums) {
            sum += v;
            sum < 0 ? sum = 0 : result = max(result, sum);
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
