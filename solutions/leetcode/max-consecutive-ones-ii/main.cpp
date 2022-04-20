class Solution {
   public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) left[i] = 1 + (i > 0 ? left[i - 1] : 0);
        }
        for (int i = n - 1; ~i; --i) {
            if (nums[i] == 1) right[i] = 1 + (i + 1 < n ? right[i + 1] : 0);
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            int v = 1;
            if (i > 0) v += left[i - 1];
            if (i + 1 < n) v += right[i + 1];
            result = max(result, v);
        }

        return result;
    }
};
