class Solution {
   public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int result = 0;
        int sum = 0;
        unordered_set<int> window;
        for (int l = 0, r = 0; r < nums.size(); ++r) {
            int v = nums[r];

            if (window.count(v) == 0) {
                window.insert(v);
                sum += v;
                result = max(result, sum);
                continue;
            }

            while (nums[l] != v) {
                window.erase(nums[l]);
                sum -= nums[l++];
            }
            ++l;
        }
        return result;
    }
};
