class Solution {
   public:
    int numSquares(int n) {
        unordered_set<int> nums;
        for (int i = 1; i * i <= n; ++i) nums.insert(i * i);

        function<bool(int, int)> search = [&](int target, int count) -> bool {
            if (count == 1) return nums.count(target);
            for (int v : nums) {
                if (v > target) continue;
                if (search(target - v, count - 1)) return true;
            }
            return false;
        };

        for (int i = 1; i < n; ++i) {
            if (search(n, i)) return i;
        }
        return n;
    }
};

class Solution {
   public:
    int numSquares(int n) {
        vector<int> dp(n + 1, numeric_limits<int>::max());
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int v = 1; v * v <= n; ++v) {
                if (int j = i - v * v; j >= 0) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n];
    }
};
