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
        int l = matrix.front().front();
        int r = matrix.back().back();

        while (l <= r) {
            int m = l + (r - l) / 2;

            int count = 0;
            for (const auto& vec : matrix) {
                count += upper_bound(vec.begin(), vec.end(), m) - vec.begin();
            }

            if (count <= k - 1) {
                l = m + 1;
            } else if (count > k - 1) {
                r = m - 1;
            }
        }

        int result = matrix.back().back();
        for (const auto& vec : matrix) {
            const auto it = upper_bound(vec.begin(), vec.end(), r);
            if (it != vec.end()) result = min(result, *it);
        }

        return result;
    }
};
