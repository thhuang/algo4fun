class Solution {
   public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, int> num_count;
        for (int v : nums1) ++num_count[v];
        for (int v : nums2) {
            if (--num_count[v] >= 0) result.push_back(v);
        }
        return result;
    }
};
