class Solution {
    const int mn = numeric_limits<int>::min();
    const int mx = numeric_limits<int>::max();

   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);

        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;

        int l = 0, r = n1;
        while (l <= r) {
            int m1 = l + (r - l) / 2;
            int l1 = m1 - 1 < 0 ? mn : nums1[m1 - 1];
            int r1 = m1 >= n1 ? mx : nums1[m1];

            int m2 = n / 2 - m1;
            int l2 = m2 - 1 < 0 ? mn : nums2[m2 - 1];
            int r2 = m2 >= n2 ? mx : nums2[m2];

            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 1) return min(r1, r2);
                return 0.5 * (max(l1, l2) + min(r1, r2));
            }

            if (l1 > r2) {
                r = m1 - 1;
            } else {
                l = m1 + 1;
            }
        }

        return 0;
    }
};

class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);

        int n1 = nums1.size();
        int n2 = nums2.size();

        int l1 = 0, r1 = n1;
        while (l1 <= r1) {
            int m1 = l1 + (r1 - l1) / 2;
            int m2 = (n1 + n2) / 2 - m1;

            int a1 = numeric_limits<int>::min();
            if (0 <= m1 - 1) a1 = nums1[m1 - 1];

            int b1 = numeric_limits<int>::max();
            if (m1 < n1) b1 = nums1[m1];

            int a2 = numeric_limits<int>::min();
            if (0 <= m2 - 1) a2 = nums2[m2 - 1];

            int b2 = numeric_limits<int>::max();
            if (m2 < n2) b2 = nums2[m2];

            if (a1 <= b2 && a2 <= b1) {
                if ((n1 + n2) % 2 == 0) {
                    return 0.5 * (min(b1, b2) + max(a1, a2));
                } else {
                    return min(b1, b2);
                }
            }

            if (a1 > b2) {
                r1 = m1 - 1;
            } else {
                l1 = m1 + 1;
            }
        }

        return -1;
    }
};
