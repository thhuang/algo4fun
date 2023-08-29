class Solution {
   public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        vector<int> penalty(n + 1, 0);
        for (int i = 0, v = 0; i < n; ++i) {
            if (customers[i] == 'N') ++v;
            penalty[i + 1] = v;
        }
        for (int i = n - 1, v = 0; i >= 0; --i) {
            if (customers[i] == 'Y') ++v;
            penalty[i] += v;
        }

        int minPenalty = numeric_limits<int>::max();
        int result;
        for (int i = 0; i <= n; ++i) {
            if (penalty[i] < minPenalty) {
                minPenalty = penalty[i];
                result = i;
            }
        }

        return result;
    }
};
