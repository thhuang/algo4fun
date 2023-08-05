class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;

        unordered_map<int, int> targetSum = {{k, 1}};
        int sum = 0;
        for (int v : nums) {
            sum += v;
            result += targetSum[sum];
            ++targetSum[sum + k];
        }

        return result;
    }
};

class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;

        unordered_map<int, int> prefixSum = {{0, 1}};
        int sum = 0;
        for (int v : nums) {
            sum += v;
            result += prefixSum[sum - k];
            ++prefixSum[sum];
        }

        return result;
    }
};
