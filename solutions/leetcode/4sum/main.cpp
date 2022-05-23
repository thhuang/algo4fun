class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                for (int l = j + 1; l < nums.size(); ++l) {
                    int r = nums.size() - 1;
                    while (l < r) {
                        long s = (long)nums[i] + nums[j] + nums[l] + nums[r];
                        if (s < target) {
                            ++l;
                        } else if (s > target) {
                            --r;
                        } else {  // s == target
                            result.push_back({nums[i], nums[j], nums[l], nums[r]});
                            while (l + 1 < nums.size() && nums[l] == nums[l + 1]) ++l;
                            ++l;
                        }
                    }
                }
                while (j + 1 < nums.size() && nums[j] == nums[j + 1]) ++j;
            }
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) ++i;
        }

        return result;
    }
};
