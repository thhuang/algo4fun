class Solution {
    struct Row {
        vector<int>::iterator it, end;
    };

   public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto cmp = [&](Row b, Row a) -> bool { return *a.it < *b.it; };

        priority_queue<Row, vector<Row>, decltype(cmp)> pq(cmp);
        for (auto& row : matrix) pq.push({row.begin(), row.end()});

        while (--k) {
            auto row = pq.top();
            pq.pop();
            row.it = next(row.it);
            if (row.it != row.end) pq.push(row);
        }

        return *pq.top().it;
    }
};

class Solution {
    struct Row {
        vector<int>::iterator it, end;
    };

   public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto comp = [&](Row a, Row b) -> bool { return *a.it > *b.it; };

        priority_queue<Row, vector<Row>, decltype(comp)> q(comp);

        for (auto& r : matrix) q.push({r.begin(), r.end()});

        while (--k) {
            auto r = q.top();
            q.pop();

            if (++r.it != r.end) q.push(r);
        }

        return *q.top().it;
    }
};

class Solution {
   public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        auto countLessThanEqualTo = [&](int t) -> int {
            int result = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (matrix[i][j] < t) ++result;
                }
            }
            return result;
        };

        int l = matrix.front().front();
        int r = matrix.back().back();
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (countLessThanEqualTo(m) < k) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return r;
    }
};

class Solution {
   public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = matrix.front().front();
        int r = matrix.back().back();
        while (l <= r) {
            int m = l + (r - l) / 2;
            int cnt = 0;
            for (const auto vec : matrix) {
                cnt += upper_bound(vec.begin(), vec.end(), m) - vec.begin();
            }
            if (cnt < k) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l;
    }
};

class Solution {
   public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = matrix.front().front() - 1;
        int r = matrix.back().back() + 1;
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            int cnt = 0;
            for (const auto vec : matrix) {
                cnt += upper_bound(vec.begin(), vec.end(), m) - vec.begin();
            }
            if (cnt < k) {
                l = m;
            } else {
                r = m;
            }
        }
        return r;
    }
};
