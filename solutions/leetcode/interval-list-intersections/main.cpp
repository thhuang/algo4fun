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

class Solution {
   public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        vector<vector<int>> result;

        int i = 0, j = 0;
        while (i < firstList.size() && j < secondList.size()) {
            int l = max(firstList[i][0], secondList[j][0]);
            int r = min(firstList[i][1], secondList[j][1]);
            if (l <= r) result.push_back({l, r});

            if (firstList[i][1] < secondList[j][1]) {
                ++i;
            } else {
                ++j;
            }
        }

        return result;
    }
};
