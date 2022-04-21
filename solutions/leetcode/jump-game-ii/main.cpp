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

class Solution {
   public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;

        int jump = 0;
        int farthest = 0;
        int jump_farthest = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > jump_farthest) {
                ++jump;
                jump_farthest = farthest;
            }

            farthest = max(farthest, i + nums[i]);

            if (farthest >= nums.size() - 1) return jump + 1;
        }

        return -1;
    }
};
