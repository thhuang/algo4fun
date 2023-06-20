class Solution {
   public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[1] == b[1]) return a[0] < b[0];
                 return a[1] < b[1];
             });

        int count = 0;
        int i = 0;
        while (i < points.size()) {
            ++count;

            int x = points[i][1];
            while (i < points.size() && points[i][0] <= x) ++i;
        }

        return count;
    }
};

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
        sort(points.begin(), points.end());
        int count = 1;
        int last_arrow = points[0][1];
        for (const auto& p : points) {
            if (last_arrow < p[0]) {
                ++count;
                last_arrow = p[1];
            } else {
                last_arrow = min(last_arrow, p[1]);
            }
        }
        return count;
    }
};
