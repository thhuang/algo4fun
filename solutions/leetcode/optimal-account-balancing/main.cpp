class Solution {
   public:
    int minTransfers(vector<vector<int>>& transactions) {
        const int mx = 12;
        array<int, mx> processed;
        processed.fill(0);
        for (auto& t : transactions) {
            processed[t[0]] -= t[2];
            processed[t[1]] += t[2];
        }

        vector<int> net;
        copy_if(processed.begin(), processed.end(), back_inserter(net),
                [](int v) -> bool { return v != 0; });

        int n = net.size();
        vector<int> memo(1 << n, -1);
        memo[0] = 0;

        function<int(int)> dfs = [&](int selected) -> int {
            if (memo[selected] != -1) return memo[selected];

            int sum = 0, result = 0;
            for (int i = 0; i < n; ++i) {
                int mask = 1 << i;
                if ((selected & mask) == 0) continue;
                sum += net[i];
                result = max(result, dfs(selected ^ mask));
            }
            if (sum == 0) ++result;

            return memo[selected] = result;
        };

        return n - dfs((1 << n) - 1);
    }
};
