class Solution {
   public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> result;
        vector<int> curr;
        function<void(int)> dfs = [&](int v) -> void {
            curr.push_back(v);
            if (curr.size() == n) {
                result.push_back(0);
                for (int i = 0; i < curr.size(); ++i)
                    result.back() = result.back() * 10 + curr[i];
            } else {
                if (v + k < 10) dfs(v + k);
                if (k > 0 && v - k >= 0) dfs(v - k);
            }
            curr.pop_back();
        };
        for (int i = 1; i <= 9; ++i) dfs(i);
        return result;
    }
};
