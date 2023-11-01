class Solution {
    int manhattan(const vector<int>& a, const vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

   public:
    vector<int> assignBikes(vector<vector<int>>& workers,
                            vector<vector<int>>& bikes) {
        int m = workers.size();
        int n = bikes.size();

        array<vector<array<int, 2>>, 2000> distPairs = {};
        for (int i = 0; i < workers.size(); ++i) {
            for (int j = 0; j < bikes.size(); ++j) {
                distPairs[manhattan(workers[i], bikes[j])].push_back({i, j});
            }
        }

        vector<bool> bikeUsed(n, false);
        vector<int> result(m, -1);
        for (const auto& pairs : distPairs) {
            for (auto [i, j] : pairs) {
                if (result[i] != -1 || bikeUsed[j]) continue;
                bikeUsed[j] = true;
                result[i] = j;
            }
        }

        return result;
    }
};
