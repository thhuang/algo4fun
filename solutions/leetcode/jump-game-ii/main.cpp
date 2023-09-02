class Solution {
   public:
    int jump(vector<int>& nums) {
        const int int_max = numeric_limits<int>::max();
        vector<int> dp(size(nums), int_max);
        dp[0] = 0;
        for (int i = 0; i < size(nums); ++i) {
            if (dp[i] == int_max) continue;
            for (int d = 1; d <= nums[i]; ++d) {
                if (i + d >= size(dp)) break;
                dp[i + d] = min(dp[i + d], dp[i] + 1);
            }
        }
        return dp.back();
    }
};

class Solution {
   public:
    int jump(vector<int>& nums) {
        int result = 0;
        for (int l = 0, r = 0; r < nums.size() - 1;) {
            ++result;
            int rNew = r;
            for (int i = l; i <= r; ++i) rNew = max(rNew, i + nums[i]);
            l = r + 1;
            r = rNew;
        }
        return result;
    }
};

class Solution {
   public:
    int jump(vector<int>& nums) {
        int result = 0;
        for (int i = 0, currStep = 0, nextStep = 0; i < nums.size(); ++i) {
            if (i > currStep) {
                currStep = nextStep;
                ++result;
            }
            nextStep = max(nextStep, i + nums[i]);
        }
        return result;
    }
};
