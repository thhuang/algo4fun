class Solution {
   public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;

        int count = 0;
        int product = 1;
        int l = 0, r = 0;
        while (r < nums.size()) {
            if (product * nums[r] >= k) {
                if (l == r) {
                    ++l, ++r;
                    continue;
                }

                count += r - l;
                product /= nums[l++];
                continue;
            }
            product *= nums[r];
            ++r;
        }

        while (l < r) count += r - l, ++l;

        return count;
    }
};

class Solution {
   public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;

        int product = 1;
        int count = 0;
        for (int l = 0, r = 0; r < nums.size(); ++r) {
            product *= nums[r];
            while (product >= k) product /= nums[l++];
            count += r - l + 1;
        }

        return count;
    }
};
