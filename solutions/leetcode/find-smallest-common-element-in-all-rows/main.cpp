class Solution {
   public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat.front().size();

        int mx = 0;
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        for (int i = 0; i < n; ++i) {
            mx = max(mat[i][0], mx);
            pq.push({mat[i][0], i, 0});
        }

        while (pq.size() == n) {
            auto [mn, i, j] = pq.top();
            pq.pop();

            if (mn == mx) return mx;

            if (++j == m) continue;
            mx = max(mat[i][j], mx);
            pq.push({mat[i][j], i, j});
        }

        return -1;
    }
};

class Solution {
   public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat.front().size();

        vector<int> pos(n, 0);
        int mx = 0;
        int cnt = 0;
        while (cnt < n) {
            for (int i = 0; i < n; ++i) {
                while (mat[i][pos[i]] < mx) {
                    if (++pos[i] == m) return -1;
                }
                if (mat[i][pos[i]] == mx) {
                    ++cnt;
                } else {
                    mx = mat[i][pos[i]];
                    cnt = 1;
                }
            }
        }

        return mx;
    }
};
