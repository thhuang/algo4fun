class Solution {
   public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int result = 0;
        if (n2 & 1) {
            for (int v : nums1) result = result ^ v;
        }
        if (n1 & 1) {
            for (int v : nums2) result = result ^ v;
        }
        return result;
    }
};
