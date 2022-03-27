class Solution {
   public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1, set2;
        for (int v : nums1) set1.insert(v);
        for (int v : nums2) set2.insert(v);

        unordered_set<int> ans1, ans2;
        for (int v : nums1) {
            if (set2.count(v)) continue;
            ans1.insert(v);
        }
        for (int v : nums2) {
            if (set1.count(v)) continue;
            ans2.insert(v);
        }

        vector<vector<int>> result(2);
        for (auto it = ans1.begin(); it != ans1.end(); ++it)
            result[0].push_back(*it);
        for (auto it = ans2.begin(); it != ans2.end(); ++it)
            result[1].push_back(*it);

        return result;
    }
};
