class Solution {
   public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = requests.size();

        int result = 0;
        vector<bool> accepts(m, false);
        function<void(int)> dfs = [&](int i) -> void {
            if (i == m) {
                int cnt = 0;
                vector<int> diff(n, 0);
                for (int j = 0; j < m; ++j) {
                    if (accepts[j]) {
                        --diff[requests[j][0]];
                        ++diff[requests[j][1]];
                        ++cnt;
                    }
                }
                for (int d : diff) {
                    if (d != 0) return;
                }
                result = max(result, cnt);
                return;
            }

            accepts[i] = true;
            dfs(i + 1);
            accepts[i] = false;
            dfs(i + 1);
        };

        dfs(0);

        return result;
    }
};
