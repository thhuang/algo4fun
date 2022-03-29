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
        int max_distance = 0;
        int current_jump_distance = 0;
        int jumps = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > current_jump_distance) {
                current_jump_distance = max_distance;
                ++jumps;
            }
            max_distance = max(max_distance, i + nums[i]);
        }
        return jumps;
    }
};
