class Solution {
   public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());

        auto isValid = [&](int x) -> bool {
            int op = maxOperations;
            for (int v : nums) {
                int cnt = (v - 1) / x;
                op -= cnt;
            }
            return op >= 0;
        };

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (isValid(m)) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return l;
    }
};
