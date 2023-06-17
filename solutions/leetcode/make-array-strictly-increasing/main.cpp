class Solution {
   public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());

        int m = arr1.size();
        int n = arr2.size();

        unordered_map<int, unordered_map<int, int>> dp;
        int mx = 1e4;

        function<int(int, int)> dfs = [&](int i, int p) -> int {
            if (i == m) return 0;
            if (dp[i].count(p)) return dp[i][p];

            int v = mx;
            if (p < arr1[i]) v = dfs(i + 1, arr1[i]);

            int j = upper_bound(arr2.begin(), arr2.end(), p) - arr2.begin();
            if (j < arr2.size()) v = min(v, 1 + dfs(i + 1, arr2[j]));

            return dp[i][p] = v;
        };

        int result = dfs(0, -1);
        if (result >= 1e4) return -1;
        return result;
    }
};
