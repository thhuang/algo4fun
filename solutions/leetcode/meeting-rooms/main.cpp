class Solution {
   public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int t = numeric_limits<int>::min();
        for (const vector<int>& in : intervals) {
            if (in[0] < t) return false;
            t = in[1];
        }
        return true;
    }
};
