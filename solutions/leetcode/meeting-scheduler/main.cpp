class Solution {
   public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1,
                                     vector<vector<int>>& slots2,
                                     int duration) {
        vector<array<int, 2>> q;
        for (const auto& s : slots1)
            q.push_back({s[0], 1}), q.push_back({s[1], -1});
        for (const auto& s : slots2)
            q.push_back({s[0], 1}), q.push_back({s[1], -1});
        sort(q.begin(), q.end(), greater<>());

        int available_count = 0;
        int start = numeric_limits<int>::max();
        while (!q.empty()) {
            auto [t, c] = q.back();
            q.pop_back();

            if (available_count == 2 && t - start >= duration) {
                return {start, start + duration};
            }

            start = t;
            available_count += c;
        }

        return {};
    }
};

class Solution {
   public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1,
                                     vector<vector<int>>& slots2,
                                     int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());

        int p1 = 0, p2 = 0;
        while (p1 < slots1.size() && p2 < slots2.size()) {
            auto& s1 = slots1[p1];
            auto& s2 = slots2[p2];

            if (s1[1] < s2[0]) {
                ++p1;
            } else if (s2[1] < s1[0]) {
                ++p2;
            } else {
                int l = max(s1[0], s2[0]);
                int r = min(s1[1], s2[1]);
                if (r - l >= duration) return {l, l + duration};
                s1[1] < s2[1] ? ++p1 : ++p2;
            }
        }

        return {};
    }
};
