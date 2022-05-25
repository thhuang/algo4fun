class Solution {
   public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();

        sort(envelopes.begin(), envelopes.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0]) return a[1] > b[1];
                 return a[0] < b[0];
             });

        vector<array<int, 2>> result;
        for (const auto& e : envelopes) {
            auto it = lower_bound(
                result.begin(), result.end(), array<int, 2>{e[0], e[1]},
                [](const array<int, 2>& value,
                   const array<int, 2>& target) -> bool {
                    return value[0] < target[0] && value[1] < target[1];
                });
            if (it == result.end()) {
                result.push_back({e[0], e[1]});
            } else {
                *it = {e[0], e[1]};
            }
        }

        return result.size();
    }
};
