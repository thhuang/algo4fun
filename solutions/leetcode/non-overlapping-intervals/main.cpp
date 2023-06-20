class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) -> bool {
            if (a[1] != b[1]) return a[1] < b[1];
            return a[0] < b[0];
        });

        int result = 0;
        int curr = intervals[0][0];
        for (auto& interval : intervals) {
            if (interval[0] < curr) {
                ++result;
            } else {
                curr = interval[1];
            }
        }

        return result;
    }
};
