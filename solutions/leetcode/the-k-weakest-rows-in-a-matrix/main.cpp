class Solution {
   public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = size(mat);
        int m = size(mat[0]);

        vector<int> result;
        int idx = 0;
        while (k) {
            int i = idx % n;
            int j = idx / n;
            ++idx;

            if (j == 0) {
                if (mat[i][j] == 0) result.push_back(i), --k;
                continue;
            }
            if (j == m) {
                if (mat[i][j - 1] == 1) result.push_back(i), --k;
                continue;
            }
            if (mat[i][j - 1] == 1 && mat[i][j] == 0) {
                result.push_back(i), --k;
                continue;
            }
        }

        return result;
    }
};

class Solution {
   public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> q;
        for (int i = 0; i < size(mat); ++i) {
            auto& r = mat[i];
            auto it =
                upper_bound(r.begin(), r.end(), 1,
                            [](int value, int entry) { return value > entry; });
            q.push({int(it - r.begin()), i});
        }

        vector<int> result(k);
        for (int i = 0; i < k; ++i) result[i] = q.top()[1], q.pop();

        return result;
    }
};
