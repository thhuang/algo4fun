class Solution {
   public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, int> counts;
        for (int v : nums1) ++counts[v];
        for (int v : nums2) {
            if (!counts[v]) continue;
            --counts[v];
            result.push_back(v);
        }
        return result;
    }
};
