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

class Solution {
   public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat.front().size();
        vector<int> result;
        vector<bool> vis(n, false);
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                if (mat[i][j] == 0 && !vis[i]) {
                    result.push_back(i);
                    vis[i] = true;
                }
                if (result.size() == k) return result;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) result.push_back(i);
            if (result.size() == k) break;
        }

        return result;
    }
};

class Solution {
   public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat.front().size();

        vector<int> result;
        vector<bool> vis(n, false);
        for (int j = 0; j <= m; ++j) {
            for (int i = 0; i < n; ++i) {
                if (vis[i]) continue;
                if (j == m || mat[i][j] == 0) {
                    result.push_back(i);
                    vis[i] = true;
                }
                if (result.size() == k) return result;
            }
        }

        return result;
    }
};

class Solution {
   public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat.front().size();

        vector<array<int, 2>> strength;

        for (int i = 0; i < m; ++i) {
            int j = lower_bound(mat[i].begin(), mat[i].end(), 0, greater<>()) -
                    mat[i].begin();
            strength.push_back({j, i});
        }

        sort(strength.begin(), strength.end());

        vector<int> result(k);
        for (int i = 0; i < k; ++i) {
            result[i] = strength[i][1];
        }

        return result;
    }
};
