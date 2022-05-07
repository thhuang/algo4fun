class Solution {
   public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int result = 0;
        unordered_map<int, int> sum_idx = {{0, -1}};

        for (int i = 0, sum = 0; i < nums.size(); ++i) {
            sum += nums[i];

            if (auto it = sum_idx.find(sum - k); it != sum_idx.end()) {
                result = max(result, i - it->second);
            }

            if (sum_idx.find(sum) == sum_idx.end()) {
                sum_idx[sum] = i;
            }
        }

        return result;
    }
};
