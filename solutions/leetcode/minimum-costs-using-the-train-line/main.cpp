class Solution {
   public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express,
                                   int expressCost) {
        int n = regular.size();
        vector<long long> result;
        array<long long, 2> dp = {0, expressCost};
        for (int i = 0; i < n; ++i) {
            dp = {min(dp[0] + regular[i], dp[1] + express[i]),
                  min(dp[0] + regular[i] + expressCost, dp[1] + express[i])};
            result.push_back(min(dp[0], dp[1]));
        }
        return result;
    }
};
