class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        bool nums1_is_shorter = nums1.size() < nums2.size();
        vector<int>& vec1 = nums1_is_shorter ? nums1 : nums2;
        vector<int>& vec2 = nums1_is_shorter ? nums2 : nums1;

        int n = vec1.size() + vec2.size();
        int half = n / 2;
        int odd = n & 1;

        int l = 0, r = vec1.size() - 1;
        while (true) {
            int m1 = l + (r - l) / 2;
            if (r < 0) m1 = -1;
            int m2 = half - m1 - 2;

            int left1 = numeric_limits<int>::min();
            int left2 = numeric_limits<int>::min();
            int right1 = numeric_limits<int>::max();
            int right2 = numeric_limits<int>::max();
            if (0 <= m1 && m1 < vec1.size()) left1 = vec1[m1];
            if (0 <= m2 && m2 < vec2.size()) left2 = vec2[m2];
            if (0 <= m1 + 1 && m1 + 1 < vec1.size()) right1 = vec1[m1 + 1];
            if (0 <= m2 + 1 && m2 + 1 < vec2.size()) right2 = vec2[m2 + 1];

            if (left1 > right2) {
                r = m1 - 1;
            } else if (left2 > right1) {
                l = m1 + 1;
            } else {
                if (odd) return min(right1, right2);
                return 0.5 * (max(left1, left2) + min(right1, right2));
            }
        }

        return 0;
    }
};

class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);

        int m = nums1.size();
        int n = nums2.size();
        bool is_odd = (m + n) % 2 == 1;

        int l = -1, r = m;
        while (l <= r) {
            int t1 = l + (r - l) / 2;
            int t2 = (n + m) / 2 - 2 - t1;

            int v10 = t1 >= 0 ? nums1[t1] : numeric_limits<int>::min();
            int v11 = t1 + 1 < m ? nums1[t1 + 1] : numeric_limits<int>::max();

            int v20 = t2 >= 0 ? nums2[t2] : numeric_limits<int>::min();
            int v21 = t2 + 1 < n ? nums2[t2 + 1] : numeric_limits<int>::max();

            if (v10 <= v21 && v20 <= v11) {
                return is_odd ? min(v11, v21)
                              : 0.5 * (max(v10, v20) + min(v11, v21));
            }

            if (v10 > v21) {
                r = t1 - 1;
            } else {  // v20 > v11
                l = t1 + 1;
            }
        }
        return 0;
    }
};
