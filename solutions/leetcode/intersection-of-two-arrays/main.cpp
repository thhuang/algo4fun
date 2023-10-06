class Solution {
   public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> nums(nums1.begin(), nums1.end());
        unordered_set<int> result;
        for (int v : nums2) {
            if (nums.count(v) > 0) {
                result.insert(v);
            }
        }
        return {result.begin(), result.end()};
    }
};
