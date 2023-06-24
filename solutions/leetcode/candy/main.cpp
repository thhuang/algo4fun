class Solution {
   public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> ones;
        for (int i = 0; i < n; ++i) {
            int l = (i - 1 < 0) ? numeric_limits<int>::max() : ratings[i - 1];
            int r = (i + 1 == n) ? numeric_limits<int>::max() : ratings[i + 1];
            if (l >= ratings[i] && ratings[i] <= r) ones.push_back(i);
        }

        vector<int> candies(n, 1);
        for (int m : ones) {
            for (int i = 1; m + i < n && ratings[m + i] > ratings[m + i - 1];
                 ++i) {
                candies[m + i] = max(candies[m + i], 1 + i);
            }
            for (int i = 1; m - i >= 0 && ratings[m - i] > ratings[m - i + 1];
                 ++i) {
                candies[m - i] = max(candies[m - i], 1 + i);
            }
        }

        return accumulate(candies.begin(), candies.end(), 0);
    }
};

class Solution {
   public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
