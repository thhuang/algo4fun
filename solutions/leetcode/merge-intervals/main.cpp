class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        for (const vector<int>& in : intervals) {
            if (result.empty() || result.back()[1] < in[0]) {
                result.push_back(in);
            } else {
                result.back()[1] = max(result.back()[1], in[1]);
            }
        }
        return result;
    }
};
