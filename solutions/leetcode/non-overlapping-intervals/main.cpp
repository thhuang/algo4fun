class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const auto &a, const auto &b) -> bool { return a[1] < b[1]; });

        int result = 0;
        int r = numeric_limits<int>::min();
        for (const auto &interval : intervals) {
            interval[0] < r ? ++result : r = interval[1];
        }

        return result;
    }
};
