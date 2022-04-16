class Solution {
   public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) {
                result = max(result, j - i);
                ++j;
            } else {
                if (i == j) {
                    ++i, ++j;
                    continue;
                }
                ++i;
            }
        }
        return result;
    }
};

class Solution {
   public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            int l = i, r = nums2.size() - 1;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (nums2[m] >= nums1[i]) {
                    result = max(result, m - i);
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        return result;
    }
};
