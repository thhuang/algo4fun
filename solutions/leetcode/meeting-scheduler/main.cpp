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
