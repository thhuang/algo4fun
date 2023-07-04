class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); ++i) {
            if (++seen[nums[i]] > 1) return true;
            if (i >= k) --seen[nums[i - k]];
        }
        return false;
    }
};
