class Solution {
   public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int count = 0;
        int r = numeric_limits<int>::min();
        for (const auto& p : pairs) {
            if (p[0] <= r) continue;
            r = p[1];
            ++count;
        }

        return count;
    }
};
