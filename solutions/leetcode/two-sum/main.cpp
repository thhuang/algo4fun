class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < size(nums); ++i) {
            if (mp.count(nums[i])) return {mp[nums[i]], i};
            mp[target - nums[i]] = i;
        }
        return {};
    }
};
