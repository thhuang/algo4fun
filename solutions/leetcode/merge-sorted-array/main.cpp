class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        reverse(nums1.begin(), nums1.begin() + m);
        reverse(nums1.begin(), nums1.end());

        int i = nums1.size() - m, j = 0;
        int p = 0;
        while (i < nums1.size() || j < n) {
            if (i >= nums1.size()) {
                nums1[p++] = nums2[j++];
            } else if (j >= n) {
                nums1[p++] = nums1[i++];
            } else if (nums1[i] < nums2[j]) {
                nums1[p++] = nums1[i++];
            } else {  // nums1[i] >= nums2[j]
                nums1[p++] = nums2[j++];
            }
        }
    }
};

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int p = m + n - 1;
        while (p >= 0) {
            if (i < 0)
                nums1[p--] = nums2[j--];
            else if (j < 0)
                nums1[p--] = nums1[i--];
            else if (nums1[i] < nums2[j])
                nums1[p--] = nums2[j--];
            else
                nums1[p--] = nums1[i--];
        }
    }
};

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int p = m + n - 1;
        while (~i && ~j)
            nums1[p--] = nums1[i] < nums2[j] ? nums2[j--] : nums1[i--];
        while (~j) nums1[p--] = nums2[j--];
    }
};
