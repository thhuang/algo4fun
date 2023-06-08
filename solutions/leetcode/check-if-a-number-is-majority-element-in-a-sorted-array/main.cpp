class Solution {
   public:
    bool isMajorityElement(vector<int>& nums, int target) {
        auto r = upper_bound(nums.begin(), nums.end(), target);
        auto l = lower_bound(nums.begin(), nums.end(), target);
        return r - l > nums.size() / 2;
    }
};
