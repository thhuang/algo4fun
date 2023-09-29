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

class Solution {
   public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = true, dec = true;
        int mn = numeric_limits<int>::max(), mx = numeric_limits<int>::min();
        for (int v : nums) {
            if (v < mx) inc = false;
            if (v > mn) dec = false;
            mn = mx = v;
        }
        return inc || dec;
    }
};
