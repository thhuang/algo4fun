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

class Solution {
   public:
    vector<int> countBits(int n) {
        if (n == 0) return {0};

        vector<int> result = {0};
        while (result.size() <= n) {
            int m = result.size();
            for (int i = 0; i < m && result.size() <= n; ++i) {
                result.push_back(result[i] + 1);
            }
        }

        return result;
    }
};
