class Solution {
   public:
    vector<int> countBits(int n) {
        vector<int> counts = {0};
        vector<int> new_counts = counts;
        for (int i = 1, j = 0; i <= n; ++i) {
            new_counts.push_back(counts[j++] + 1);
            if (j == counts.size()) {
                j = 0;
                counts = new_counts;
            }
        }
        return new_counts;
    }
};

class Solution {
   public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            result[i] = result[i & (i - 1)] + 1;
        }
        return result;
    }
};
