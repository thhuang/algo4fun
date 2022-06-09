class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) -> bool {
                 if (a[0] != b[0]) return a[0] < b[0];
                 return a[1] < b[1];
             });

        int count = 0;
        int curr_end = numeric_limits<int>::min();
        for (auto interval : intervals) {
            if (interval[0] < curr_end) {
                ++count;
                curr_end = min(curr_end, interval[1]);
                continue;
            }
            curr_end = interval[1];
        }

        return count;
    }
};

class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) -> bool {
                 if (a[0] == b[0]) return a[1] < b[1];
                 return a[0] < b[0];
             });

        int n = intervals.size();
        vector<int> dp(n, n);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            int j = lower_bound(intervals.begin(), intervals.end(), intervals[i][1],
                                [](const vector<int>& v, int t) -> bool {
                                    return v[0] < t;
                                }) - intervals.begin();
            if (i + 1 < n) dp[i + 1] = min(dp[i + 1], dp[i] + 1);
            if (j < n) dp[j] = min(dp[j], dp[i] + j - i - 1);
        }

        return dp.back();
    }
};
