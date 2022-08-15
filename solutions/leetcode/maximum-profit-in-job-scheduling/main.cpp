class Solution {
   public:
    int jobScheduling(vector<int>& start_time, vector<int>& end_time,
                      vector<int>& profit) {
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
                                }) -
                    jobs.begin();
            return dp[i] = max(dfs(i + 1), profit[jobs[i]] + dfs(j));
        };

        return dfs(0);
    }
};

class Solution {
   public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        int n = profit.size();

        vector<array<int, 3>> jobs(n);
        for (int i = 0; i < n; ++i)
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        sort(jobs.begin(), jobs.end());

        int mx = 0;
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>>
            pq;  // {end time, max profit}
        for (const auto& [l, r, v] : jobs) {
            while (!pq.empty() && pq.top()[0] <= l) {
                mx = max(mx, pq.top()[1]);
                pq.pop();
            }
            pq.push({r, mx + v});
        }

        int result = 0;
        while (!pq.empty()) {
            result = max(result, pq.top()[1]);
            pq.pop();
        }

        return result;
    }
};
