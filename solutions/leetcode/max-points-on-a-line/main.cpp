class Solution {
   public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        int result = 1;
        for (int i = 0; i + 1 < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dx0 = points[i][0] - points[j][0];
                int dy0 = points[i][1] - points[j][1];
                int count = 2;
                for (int k = j + 1; k < n; ++k) {
                    int dx1 = points[i][0] - points[k][0];
                    int dy1 = points[i][1] - points[k][1];
                    if (dy0 * dx1 == dy1 * dx0) ++count;
                }
                result = max(result, count);
            }
        }

        return result;
    }
};

class Solution {
    int gcd(int a, int b) {
        if (a < b) swap(a, b);
        if (b == 0) return a;
        return gcd(b, a % b);
    }

   public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0]) return a[1] < b[1];
                 return a[0] < b[0];
             });

        // (y1 - y0) * x - (x1 - x0) * y + c = 0
        int result = 1;
        unordered_map<
            int, unordered_map<int, unordered_map<int, unordered_set<int>>>>
            line_points;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int x0 = points[i][0], y0 = points[i][1];
                int x1 = points[j][0], y1 = points[j][1];
                int dx = x1 - x0, dy = y1 - y0;

                int v = gcd(abs(dx), abs(dy));
                int a = v ? dy / v : dy;
                int b = v ? dx / v : dx;
                int c = a * points[i][0] - b * points[i][1];
                line_points[a][b][c].insert(i);
                line_points[a][b][c].insert(j);
                result = max(result, (int)line_points[a][b][c].size());
            }
        }

        return result;
    }
};

class Solution {
   public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int result = 0;

        for (int i = 0; i < n; ++i) {
            int max_count = 0;
            unordered_map<long long, int> slope_count;

            for (int j = 0; j < n; ++j) {
                if (i == j) continue;

                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                long long slope = llround((double)dy / dx * 1e9);
                max_count = max(max_count, ++slope_count[slope]);
            }

            result = max(result, max_count + 1);
        }

        return result;
    }
};
