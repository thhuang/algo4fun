class Solution {
   public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        vector<vector<int>> result;

        for (auto interval : firstList) {
            auto b = lower_bound(
                secondList.begin(), secondList.end(), interval[0],
                [](const vector<int>& in, int v) -> bool { return in[1] < v; });

            auto e = upper_bound(
                secondList.begin(), secondList.end(), interval[1],
                [](int v, const vector<int>& in) -> bool { return v < in[0]; });

            for (auto it = b; it != e; ++it) {
                int l = max(it->at(0), interval[0]);
                int r = min(it->at(1), interval[1]);
                result.push_back({l, r});
            }
        }

        return result;
    }
};
