class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int t = n - k;

        auto partition = [&](int l, int r, int i) -> int {
            swap(nums[i], nums[r]);
            int p = l;
            for (int j = l; j < r; ++j) {
                if (nums[j] < nums[r]) {
                    swap(nums[j], nums[p++]);
                }
            }
            swap(nums[p], nums[r]);
            return p;
        };

        int l = 0, r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            m = partition(l, r, m);
            if (m <= t) {
                l = m + 1;
            } else {  // m > t
                r = m - 1;
            }
        }

        return nums[r];
    }
};
