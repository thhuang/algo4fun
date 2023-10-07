class Solution {
   public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> startIdx;
        for (int i = 0; i < intervals.size(); ++i) {
            startIdx.push_back({intervals[i][0], i});
        }

        sort(startIdx.begin(), startIdx.end());

        vector<int> result;
        for (vector<int>& interval : intervals) {
            auto it = lower_bound(
                startIdx.begin(), startIdx.end(), interval[1],
                [](pair<int, int>& e, int t) -> bool { return e.first < t; });
            if (it == startIdx.end()) {
                result.push_back(-1);
            } else {
                result.push_back(it->second);
            }
        }

        return result;
    }
};

class Solution {
   public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<array<int, 2>> startIdx;
        for (int i = 0; i < intervals.size(); ++i) {
            startIdx.push_back({intervals[i][0], i});
        }

        sort(startIdx.begin(), startIdx.end());

        vector<int> result;
        for (vector<int>& interval : intervals) {
            int l = -1, r = startIdx.size();
            while (r - l > 1) {
                int m = l + (r - l) / 2;
                if (startIdx[m][0] < interval[1]) {
                    l = m;
                } else {
                    r = m;
                }
            }

            if (r == startIdx.size()) {
                result.push_back(-1);
            } else {
                result.push_back(startIdx[r][1]);
            }
        }

        return result;
    }
};
