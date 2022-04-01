class Solution {
   public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = numeric_limits<int>::min();
        int curr_max = values[0];
        for (int i = 1; i < values.size(); ++i) {
            ans = max(ans, curr_max + values[i] - i);
            curr_max = max(curr_max, values[i] + i);
        }
        return ans;
    }
};
