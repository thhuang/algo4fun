class Solution {
   public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        unordered_set<int> ans1, ans2;
        for (int v : nums1) {
            if (s2.count(v) == 0) ans1.insert(v);
        }
        for (int v : nums2) {
            if (s1.count(v) == 0) ans2.insert(v);
        }
        vector<vector<int>> result(2);
        result[0] = {ans1.begin(), ans1.end()};
        result[1] = {ans2.begin(), ans2.end()};
        return result;
    }
};
