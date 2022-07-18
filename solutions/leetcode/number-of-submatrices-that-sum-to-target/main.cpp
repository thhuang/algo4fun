class Solution {
   public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix.front().size();

        vector<vector<unordered_map<int, int>>> prefix(n, vector<unordered_map<int, int>>(n, {{0, 1}}));
        vector<vector<int>> sum(n, vector<int>(n, 0));

        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int l = 0; l < n; ++l) {
                int s = 0;
                for (int r = l; r < n; ++r) {
                    s += matrix[i][r];
                    sum[l][r] += s;
                    count += prefix[l][r][sum[l][r] - target];
                    ++prefix[l][r][sum[l][r]];
                }
            }
        }

        return count;
    }
};

class Solution {
   public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix.front().size();

        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0, s = 0; j < n; ++j) {
                s += matrix[i][j];
                prefix[i + 1][j + 1] = prefix[i][j + 1] + s;
            }
        }

        int count = 0;
        for (int l = 0; l < n; ++l) {
            for (int r = l; r < n; ++r) {
                unordered_map<int, int> mp = {{0, 1}};
                for (int i = 0; i < m; ++i) {
                    int s = prefix[i + 1][r + 1] - prefix[i + 1][l];
                    count += mp[s - target];
                    ++mp[s];
                }
            }
        }

        return count;
    }
};
