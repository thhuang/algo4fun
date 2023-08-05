class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> target_count;
        target_count[k] = 1;

        int count = 0;
        int accumulate = 0;
        for (int v : nums) {
            accumulate += v;
            count += target_count[accumulate];
            ++target_count[accumulate + k];
        }

        return count;
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
