class Solution {
   public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for (int i = 0; i < size(accounts); ++i) {
            int sum = 0;
            for (int j = 0; j < size(accounts[i]); ++j) {
                sum += accounts[i][j];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};
