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
