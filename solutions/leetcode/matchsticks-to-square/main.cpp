class Solution {
   public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int sum = 0;
        for (int v : matchsticks) sum += v;
        if (sum % 4 != 0) return false;
        if (sum == 0) return true;

        int target = sum / 4;
        vector<bool> used(n, false);
        function<bool(int, int, int)> dfs = [&](int i, int t, int k) -> bool {
            if (t == 0) {
                if (k == 3) return true;
                ++k;
                t = target;
                i = 0;
            }
            if (i >= n) return false;

            if (used[i] == false && matchsticks[i] <= t) {
                used[i] = true;
                if (dfs(i + 1, t - matchsticks[i], k)) return true;
                used[i] = false;
            }

            if (dfs(i + 1, t, k)) return true;

            return false;
        };

        return dfs(0, target, 1);
    }
};
