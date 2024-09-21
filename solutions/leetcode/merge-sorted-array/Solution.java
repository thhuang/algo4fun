class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        for (int p = m + n - 1; p >= 0; --p) {
            if (i < 0) {
                nums1[p] = nums2[j--];
            } else if (j < 0) {
                break;
            } else if (nums1[i] > nums2[j]) {
                nums1[p] = nums1[i--];
            } else { // nums2[j] >= nums1[i]
                nums1[p] = nums2[j--];
            }
        }
    }
}
