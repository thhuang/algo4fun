class Solution {
   public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size() / 3;

        sort(piles.begin(), piles.end(), greater<>());

        int result = 0;
        for (int i = 0; i < n; ++i) {
            result += piles[i * 2 + 1];
        }

        return result;
    }
};
