class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int diff = numeric_limits<int>::max();

        for (int i = 0; i < nums.size(); ++i) {
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(sum - target) < abs(diff)) {
                    diff = sum - target;
                }

                if (sum == target) return target;
                if (sum < target) {
                    ++l;
                } else {  // sum > target
                    --r;
                }
            }
        }

        return target + diff;
    }
};
