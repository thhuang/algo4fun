class Solution {
   public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + nums[i];
        }
        vector<int> result;
        for (int i = 0, prefix = 0; i < n; ++i) {
            int l = nums[i] * i - prefix;
            int r = suffix[i + 1] - nums[i] * (n - i - 1);
            result.push_back(l + r);
            prefix += nums[i];
        }
        return result;
    }
};
