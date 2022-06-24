class Solution {
   public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int result = numeric_limits<int>::max();
        vector<unordered_map<int, unordered_set<int>>> vis(bikes.size());

        function<void(int, int, int, int)> search =
            [&](int i, int assigned, int count, int dist) -> void {
            if (count == workers.size()) {
                result = min(result, dist);
                return;
            }
            if (bikes.size() - i < workers.size() - count) return;
            if (dist >= result) return;

            if (vis[i][assigned].count(dist)) return;
            vis[i][assigned].insert(dist);

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

class Solution {
   public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<int> cache(1 << bikes.size(), -1);

        function<int(int, int)> search = [&](int i, int assigned) -> int {
            if (i == workers.size()) return 0;
            if (cache[assigned] != -1) return cache[assigned];

            int result = numeric_limits<int>::max();
            for (int j = 0, mask = 1; j < bikes.size(); ++j, mask <<= 1) {
                if (assigned & mask) continue;
                int d = abs(workers[i][0] - bikes[j][0]) +
                        abs(workers[i][1] - bikes[j][1]);
                result = min(result, d + search(i + 1, assigned | mask));
            }
            return cache[assigned] = result;
        };

        return search(0, 0);
    }
};
