class Solution {
   public:
    int minimizeArrayValue(vector<int>& nums) {
        int result = 0;

        long long sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            int avg = sum / (i + 1);
            if (sum % (i + 1)) ++avg;
            result = max(result, avg);
        }

        return result;
    }
};
