class Solution {
   public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int v : nums) {
                if (i - v < 0) continue;
                dp[i] += dp[i - v];
            }
        }
        return dp.back();
    }
};

class Solution {
   public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> cache(target + 1, -1);
        cache[0] = 1;
        function<int(int)> calculate = [&](int x) -> int {
            if (cache[x] != -1) return cache[x];
            cache[x] = 0;
            for (int v : nums) {
                if (x - v >= 0) cache[x] += calculate(x - v);
            }
            return cache[x];
        };
        return calculate(target);
    }
};

class Solution {
   public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= target; ++i) {
            if (dp[i] == 0) continue;
            for (int v : nums) {
                if (target - i < v) continue;
                dp[i + v] += dp[i];
            }
        }
        return dp.back();
    }
};
