class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int result = *max_element(nums.begin(), nums.end());
        if (result < 0) return result;

        int sum = 0;
        for (int v : nums) {
            sum = max(0, sum += v);
            result = max(result, sum);
        }

        return result;
    }
};

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int result = numeric_limits<int>::min();

        int sum = 0;
        for (int v : nums) {
            sum = max(0, sum) + v;
            result = max(result, sum);
        }

        return result;
    }
};
