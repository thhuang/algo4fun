class Solution {
   public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals,
                                       vector<int>& toBeRemoved) {
        vector<vector<int>> result;

        int n = intervals.size();
        int i = 0;

        for (; i < n && intervals[i][1] <= toBeRemoved[0]; ++i)
            result.push_back(intervals[i]);
        for (; i < n && intervals[i][0] < toBeRemoved[1]; ++i) {
            if (toBeRemoved[0] <= intervals[i][0] &&
                intervals[i][1] <= toBeRemoved[1])
                continue;
            if (intervals[i][0] < toBeRemoved[0]) {
                result.push_back({intervals[i][0], toBeRemoved[0]});
            }
            if (toBeRemoved[1] < intervals[i][1]) {
                result.push_back({toBeRemoved[1], intervals[i][1]});
            }
        }
        for (; i < n; ++i) result.push_back(intervals[i]);

        return result;
    }
};
