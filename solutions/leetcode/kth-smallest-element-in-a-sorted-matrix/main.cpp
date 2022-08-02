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

        int m;
        while (l <= r) {
            m = l + (r - l) / 2;

            int lteq = 0;
            for (const vector<int>& vec : matrix) {
                int v = upper_bound(vec.begin(), vec.end(), m) - vec.begin();
                if (v == 0) break;
                lteq += v;
            }

            if (lteq < k) {
                l = m + 1;
            } else {  // lteq >= k
                r = m - 1;
            }
        }

        int result = matrix.back().back();
        for (const vector<int>& vec : matrix) {
            auto it = upper_bound(vec.begin(), vec.end(), r);
            if (it != vec.end()) result = min(result, *it);
        }

        return result;
    }
};
