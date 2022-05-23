class Solution {
   public:
    bool isMonotonic(vector<int>& nums) {
        auto increasing = [&]() -> bool {
            for (int i = 0; i < nums.size() - 1; ++i) {
                if (nums[i] <= nums[i + 1]) continue;
                return false;
            }
            return true;
        };

        auto decreasing = [&]() -> bool {
            for (int i = 0; i < nums.size() - 1; ++i) {
                if (nums[i] >= nums[i + 1]) continue;
                return false;
            }
            return true;
        };

        return increasing() || decreasing();
    }
};
