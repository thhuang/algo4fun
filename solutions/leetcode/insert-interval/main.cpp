class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> result;
        bool inserted = false;
        for (const vector<int>& in : intervals) {
            if (inserted || in[1] < newInterval[0]) {
                result.push_back(in);
            } else if (newInterval[1] < in[0]) {
                result.push_back(newInterval);
                result.push_back(in);
                inserted = true;
            } else {
                newInterval = {min(newInterval[0], in[0]),
                               max(newInterval[1], in[1])};
            }
        }
        if (!inserted) result.push_back(newInterval);
        return result;
    }
};
