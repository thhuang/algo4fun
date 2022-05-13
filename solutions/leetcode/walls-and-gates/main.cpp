class Solution {
    vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = rooms.front().size();

        vector<array<int, 2>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rooms[i][j] == 0) q.push_back({i, j});
            }
        }

        int dist = 0;
        while (!q.empty()) {
            vector<array<int, 2>> new_q;

            for (auto [i, j] : q) {
                if (rooms[i][j] < dist) continue;
                rooms[i][j] = dist;

                for (auto [di, dj] : directions) {
                    int ii = i + di;
                    int jj = j + dj;
                    if (ii < 0 || ii >= m || jj < 0 || jj >= n) continue;
                    new_q.push_back({ii, jj});
                }
            }

            q = move(new_q);
            ++dist;
        }
    }
};

class Solution {
    vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    const int inf = numeric_limits<int>::max();

   public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = rooms.front().size();

        deque<array<int, 2>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rooms[i][j] == 0) q.push_back({i, j});
            }
        }

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop_front();
            for (auto [di, dj] : directions) {
                int ii = i + di;
                int jj = j + dj;
                if (ii < 0 || ii >= m || jj < 0 || jj >= n) continue;
                if (rooms[ii][jj] != inf) continue;
                rooms[ii][jj] = rooms[i][j] + 1;
                q.push_back({ii, jj});
            }
        }
    }
};
