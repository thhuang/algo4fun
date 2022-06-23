class Solution {
   public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) return true;
        int sum = maxChoosableInteger * (1 + maxChoosableInteger) / 2;
        if (sum < desiredTotal) return false;

        vector<bool> cache(1 << maxChoosableInteger, false);
        vector<bool> vis(1 << maxChoosableInteger, false);
        function<bool(int, int)> dfs = [&](int state, int target) -> bool {
            if (target <= 0) return false;
            if (vis[state]) return cache[state];

            bool result = false;
            for (int i = 1; i <= maxChoosableInteger; ++i) {
                int mask = 1 << (i - 1);
                if (state & mask) continue;
                if (!dfs(state | mask, target - i)) {
                    result = true;
                    break;
                }
            }

            vis[state] = true;
            return cache[state] = result;
        };

        return dfs(0, desiredTotal);
    }
};
