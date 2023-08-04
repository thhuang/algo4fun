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

class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int l = n - 2;
        while (l >= 0 && nums[l] >= nums[l + 1]) --l;

        if (l < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int r = n - 1;
        while (nums[l] >= nums[r]) --r;

        swap(nums[l], nums[r]);

        reverse(nums.begin() + l + 1, nums.end());
    }
};
