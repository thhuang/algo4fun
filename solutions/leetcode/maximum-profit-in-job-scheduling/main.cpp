class Solution {
   public:
    int jobScheduling(vector<int>& start_time, vector<int>& end_time, vector<int>& profit) {
        int n = start_time.size();
        
        vector<int> jobs(n);
        iota(jobs.begin(), jobs.end(), 0);
        sort(jobs.begin(), jobs.end(), [&](int a, int b) -> bool {
            return start_time[a] < start_time[b];
        });
        
        vector<int> dp(n, -1);
        function<int(int)> dfs = [&](int i) -> int {
            if (i >= n) return 0;
            if (~dp[i]) return dp[i];
            int j = upper_bound(jobs.begin(), jobs.end(), jobs[i],
                                [&](int t, int v) -> bool {
                                    return end_time[t] <= start_time[v];
                                }) - jobs.begin();
            return dp[i] = max(dfs(i + 1), profit[jobs[i]] + dfs(j));
        };
        
        return dfs(0);
    }
};
