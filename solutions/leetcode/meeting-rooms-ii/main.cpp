class Solution {
   public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<array<int, 2>> t(intervals.size() * 2);
        for (int i = 0; i < t.size(); i += 2) {
            const auto& interval = intervals[i / 2];
            t[i] = {interval[0], 1};
            t[i + 1] = {interval[1], -1};
        }

        sort(t.begin(), t.end(),
             [](const array<int, 2>& a, const array<int, 2>& b) {
                 if (a[0] == b[0]) return a[1] < b[1];
                 return a[0] < b[0];
             });

        int result = 0;
        for (int i = 0, c = 0; i < t.size(); ++i) {
            result = max(result, c += t[i][1]);
        }

        return result;
    }
};

class Solution {
   public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int result = 0;
        vector<array<int, 2>> events;
        for (const vector<int>& in : intervals) {
            events.push_back({in[0], 1});
            events.push_back({in[1], -1});
        }

        sort(events.begin(), events.end());

        int rooms = 0;
        for (auto [_, d] : events) {
            result = max(result, rooms += d);
        }

        return result;
    }
};
