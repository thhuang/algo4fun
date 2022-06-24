class Solution {
   public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int result = numeric_limits<int>::max();
        function<void(int, int, int, int)> search =
            [&](int i, int assigned, int count, int dist) -> void {
            if (count == workers.size()) {
                result = min(result, dist);
                return;
            }
            if (bikes.size() - i < workers.size() - count) return;
            if (dist >= result) return;
            search(i + 1, assigned, count, dist);
            for (int j = 0; j < workers.size(); ++j) {
                int mask = 1 << j;
                if (assigned & mask) continue;
                search(i + 1, assigned | mask, count + 1,
                       dist + abs(bikes[i][0] - workers[j][0]) +
                           abs(bikes[i][1] - workers[j][1]));
            }
        };
        search(0, 0, 0, 0);
        return result;
    }
};
