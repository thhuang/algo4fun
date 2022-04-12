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
