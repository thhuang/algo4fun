class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        for (const vector<int>& interval : intervals) {
            if (result.size() == 0 || result.back()[1] < interval[0]) {
                result.push_back(interval);
                continue;
            }
            result.back()[1] = max(result.back()[1], interval[1]);
        }

        return result;
    }
};
