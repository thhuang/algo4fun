class Solution {
   public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),
             [](auto& a, auto& b) -> bool { return a[1] < b[1]; });

        int result = 0;
        int v = numeric_limits<int>::min();
        for (auto& p : pairs) {
            if (p[0] <= v) continue;
            ++result;
            v = p[1];
        }

        return result;
    }
};
