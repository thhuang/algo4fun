class Solution {
   public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1,
                                     vector<vector<int>>& slots2,
                                     int duration) {
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> q;
        for (const auto& s : slots1) q.push({s[0], 1}), q.push({s[1], -1});
        for (const auto& s : slots2) q.push({s[0], 1}), q.push({s[1], -1});

        int available_count = 0;
        int start = numeric_limits<int>::max();
        while (!q.empty()) {
            auto [t, c] = q.top();
            q.pop();

            if (available_count == 2 && t - start >= duration) {
                return {start, start + duration};
            }

            start = t;
            available_count += c;
        }

        return {};
    }
};
