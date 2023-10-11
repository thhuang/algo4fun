class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto result = points;
        sort(result.begin(), result.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
             });
        return {result.begin(), result.begin() + k};
    }
};

class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        int l = 0, r = n - 1;

        auto partition = [&](int m) {
            int t = dist(points[m][0], points[m][1]);
            swap(points[m], points[r]);

            int p = l, pl = l, pr = r - 1;
            while (p <= pr) {
                if (dist(points[p][0], points[p][1]) <= t) {
                    swap(points[pl++], points[p++]);
                } else {
                    swap(points[pr--], points[p]);
                }
            }

            swap(points[pl], points[r]);

            return pl;
        };

        while (l <= r) {
            int m = l + rand() % (r - l + 1);

            m = partition(m);

            if (m < k) {
                l = m + 1;
            } else {  // m >= k
                r = m - 1;
            }
        }

        return {points.begin(), points.begin() + k};
    }

    int dist(int x, int y) { return x * x + y * y; }
};

class Solution {
    int distance2(const vector<int>& p) { return p[0] * p[0] + p[1] * p[1]; }

   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        function<int(int, int, int)> partition = [&](int l, int r,
                                                     int t) -> int {
            swap(points[r], points[t]);
            int p = l;
            for (int i = l; i < r; ++i) {
                if (distance2(points[i]) <= distance2(points[r])) {
                    swap(points[i], points[p++]);
                }
            }
            swap(points[p], points[r]);
            return p;
        };

        int l = 0, r = points.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            m = partition(l, r, m);
            if (m < k) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return {points.begin(), points.begin() + k};
    }
};
