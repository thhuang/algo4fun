class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        int n = size(nums);
        int i = n - 1;
        while (i > 0) {
            if (nums[i - 1] < nums[i]) break;
            --i;
        }

        if (i == 0) {
            reverse(begin(nums), end(nums));
            return;
        }

        int j = n - 1;
        while (i < j) {
            if (nums[j] > nums[i - 1]) break;
            --j;
        }

        swap(nums[j], nums[i - 1]);
        reverse(begin(nums) + i, end(nums));
    }
};
