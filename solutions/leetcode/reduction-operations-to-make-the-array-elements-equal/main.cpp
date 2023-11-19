class Solution {
   public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        int l = 1;
        while (l < n && nums[l - 1] == nums[l]) {
            ++l;
        }
        --l;

        int result = 0;

        for (int i = l + 1; i < n; ++i) {
            result += n - i;
            while (i + 1 < n && nums[i] == nums[i + 1]) {
                ++i;
            }
        }

        return result;
    }
};
