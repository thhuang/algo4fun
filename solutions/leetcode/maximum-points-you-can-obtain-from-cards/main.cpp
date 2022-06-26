class Solution {
   public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int t = n - k;

        int sum = 0;
        for (int v : cardPoints) sum += v;
        if (t == 0) return sum;

        int curr = 0;
        for (int i = 0; i < t - 1; ++i) curr += cardPoints[i];

        int result = 0;
        for (int i = t - 1; i < n; ++i) {
            curr += cardPoints[i];
            result = max(result, sum - curr);
            curr -= cardPoints[i - t + 1];
        }

        return result;
    }
};
