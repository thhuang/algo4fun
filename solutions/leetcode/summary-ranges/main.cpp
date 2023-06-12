class Solution {
   public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) return {};

        vector<string> result;
        for (int l = 0, r = 0; l < nums.size();) {
            while (r < nums.size() && (long long)nums[l] + r - l == nums[r]) ++r;

            if (r - l == 1) {
                result.push_back(to_string(nums[l]));
            } else {
                result.push_back(to_string(nums[l]) + "->" + to_string(nums[r - 1]));
            }

            l = r;
        }

        return result;
    }
};
