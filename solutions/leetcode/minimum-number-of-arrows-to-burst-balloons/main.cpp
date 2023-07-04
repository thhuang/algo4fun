class Solution {
   public:
    int findMinArrowShots(vector<vector<int>>& points) {
        priority_queue<int, vector<int>, greater<>> pq;
        vector<int> shots;
        for (auto& p : points) shots.push_back(p[1]);
        sort(shots.begin(), shots.end());
        sort(points.begin(), points.end());

        int result = 0;
        for (int l = 0, i = 0; l < points.size(); ++i) {
            if (!pq.empty() && pq.top() == shots[i]) {
                pq.pop();
                continue;
            }

            int r = l;
            while (r < points.size() && points[r][0] <= shots[i]) {
                pq.push(points[r][1]);
                ++r;
            }
            pq.pop();

            if (l < r) ++result;
            l = r;
        }

        return result;
    }
};

class Solution {
   public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),
             [](const auto& a, const auto& b) -> bool {
                 if (a[1] != b[1]) return a[1] < b[1];
                 return a[0] < b[0];
             });

        int result = 0;

        for (int i = 0; i < points.size();) {
            ++result;
            int x = points[i][1];
            while (i < points.size() && points[i][0] <= x) ++i;
        }

        return result;
    }
};

class Solution {
   public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());

        int result = 1;
        int lastArrow = points[0][1];

        for (const auto& p : points) {
            if (lastArrow < p[0]) {
                ++result;
                lastArrow = p[1];
            } else {
                lastArrow = min(lastArrow, p[1]);
            }
        }

        return result;
    }
};

class Solution {
   public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),
             [](auto& a, auto& b) -> bool { return a[1] < b[1]; });

        int result = 1;
        int curr = points[0][1];
        for (auto& p : points) {
            if (p[0] <= curr) continue;
            ++result;
            curr = p[1];
        }

        return result;
    }
};
