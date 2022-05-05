class Solution {
   public:
    int numSquares(int n) {
        vector<int> dp(n + 1, numeric_limits<int>::max());
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int v = 1; i + v * v <= n; ++v) {
                int j = i + v * v;
                dp[j] = min(dp[j], dp[i] + 1);
            }
        }
        return dp[n];
    }
};

class Solution {
   public:
    int numSquares(int n) {
        vector<int> dp(n + 1, numeric_limits<int>::max());
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; i - j * j >= 0; ++j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp.back();
    }
};

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
