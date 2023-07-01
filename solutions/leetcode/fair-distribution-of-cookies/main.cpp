class Solution {
   public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> got(k, 0);
        int result = numeric_limits<int>::max();

        function<void(int)> dfs = [&](int i) -> void {
            if (i == cookies.size()) {
                result = min(result, *max_element(got.begin(), got.end()));
                return;
            }
            for (int j = 0; j < k; ++j) {
                if (got[j] + cookies[i] >= result) continue;
                got[j] += cookies[i];
                dfs(i + 1);
                got[j] -= cookies[i];
            }
        };

        dfs(0);

        return result;
    }
};

class Solution {
   public:
    int distributeCookies(vector<int>& cookies, int k) {
        int result = accumulate(cookies.begin(), cookies.end(), 0);
        vector<int> got(k, 0);
        function<void(int)> dfs = [&](int i) -> void {
            if (i == cookies.size()) {
                result = min(result, *max_element(got.begin(), got.end()));
                return;
            }

            for (int j = 0; j < k; ++j) {
                got[j] += cookies[i];
                if (got[j] < result) dfs(i + 1);
                got[j] -= cookies[i];
            }
        };

        dfs(0);

        return result;
    }
};
