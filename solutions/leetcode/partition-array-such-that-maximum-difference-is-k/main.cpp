class Solution {
   public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int count = 1;
        for (int l = 0, r = 0; r < nums.size(); ++r) {
            if (nums[r] - nums[l] <= k) continue;
            ++count;
            l = r;
        }

        return count;
    }
};
