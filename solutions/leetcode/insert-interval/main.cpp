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

class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        if (intervals.empty() || newInterval[1] < intervals.front()[0]) {
            vector<vector<int>> result = {newInterval};
            copy(intervals.begin(), intervals.end(), back_inserter(result));
            return result;
        }

        if (intervals.back()[1] < newInterval[0]) {
            vector<vector<int>> result = intervals;
            result.push_back(newInterval);
            return result;
        }

        vector<vector<int>> result;

        bool inserted = false;
        for (vector<int>& interval : intervals) {
            if (interval[1] < newInterval[0]) {
                result.push_back(interval);
                continue;
            }

            if (!inserted) {
                inserted = true;
                result.push_back(newInterval);
            }

            if (newInterval[1] < interval[0]) {
                result.push_back(interval);
                continue;
            }

            result.back()[0] = min(result.back()[0], interval[0]);
            result.back()[1] = max(result.back()[1], interval[1]);
        }

        return result;
    }
};

class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> result;

        bool inserted = false;
        for (vector<int>& interval : intervals) {
            if (interval[1] < newInterval[0]) {
                result.push_back(interval);
                continue;
            }

            if (!inserted) {
                inserted = true;
                result.push_back(newInterval);
            }

            if (newInterval[1] < interval[0]) {
                result.push_back(interval);
                continue;
            }

            result.back()[0] = min(result.back()[0], interval[0]);
            result.back()[1] = max(result.back()[1], interval[1]);
        }

        if (!inserted) result.push_back(newInterval);

        return result;
    }
};

class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> result;

        int i = 0;
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            ++i;
        }

        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            ++i;
        }
        result.push_back(newInterval);

        while (i < intervals.size()) {
            result.push_back(intervals[i]);
            ++i;
        }

        return result;
    }
};
