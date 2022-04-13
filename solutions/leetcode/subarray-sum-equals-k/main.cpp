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
