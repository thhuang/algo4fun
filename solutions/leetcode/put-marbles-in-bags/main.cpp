class Solution {
   public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> pairs(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            pairs[i] = weights[i] + weights[i + 1];
        }

        sort(pairs.begin(), pairs.end());

        long long result = 0;
        for (int i = 0; i < k - 1; ++i) {
            result += pairs[n - 2 - i] - pairs[i];
        }

        return result;
    }
};
