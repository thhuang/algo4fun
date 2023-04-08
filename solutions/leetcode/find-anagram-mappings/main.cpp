class Solution {
   public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) mp[nums2[i]] = i;

        vector<int> result;
        for (int v : nums1) result.push_back(mp[v]);

        return result;
    }
};
