class Solution {
   public:
    int specialArray(vector<int>& nums) {
        int l = 0, r = nums.size();
        while (l <= r) {
            int m = l + (r - l) / 2;
            int count = 0;
            for (int v : nums) {
                if (v >= m) ++count;
            }

            if (m == count) return m;
            if (count > m) {
                l = m + 1;
            } else {  // count < m
                r = m - 1;
            }
        }

        return -1;
    }
};
