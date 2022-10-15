class Solution {
   public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> adj(nums.size());
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        function<int(int, int, int)> dfs = [&](int u, int p, int t) -> int {
            int sum = nums[u];
            for (int v : adj[u]) {
                if (v == p) continue;
                sum += dfs(v, u, t);
                if (sum > t) return t + 1;
            }
            if (sum == t) return 0;
            return sum;
        };

        for (int i = n; i > 1; --i) {
            if (total % i) continue;
            if (dfs(0, -1, total / i)) continue;
            return i - 1;
        }

        return 0;
    }
};
