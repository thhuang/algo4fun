class Solution {
    int medium(vector<int>& nums) {
        int n = nums.size();

        function<int(int, int, int)> partition = [&](int l, int r, int m) -> int {
            swap(nums[m], nums[r]);
            int p = l;
            for (int i = l; i < r; ++i) {
                if (nums[i] < nums[r]) swap(nums[i], nums[p++]);
            }
            swap(nums[p], nums[r]);
            return p;
        };

        int l = 0, r = n - 1, t = n / 2;
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

   public:
    int minMoves2(vector<int>& nums) {
        int m = medium(nums);
        int result = 0;
        for (int v : nums) result += abs(v - m);
        return result;
    }
};
