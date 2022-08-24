class Solution {
   public:
    int longestSubstring(string s, int k) {
        if (s.empty()) return 0;

        array<vector<int>, 26> count;
        for (int i = 0; i < s.size(); ++i) count[s[i] - 'a'].push_back(i);

        vector<int> breaks = {-1};
        for (int i = 0; i < count.size(); ++i) {
            if (0 < count[i].size() && count[i].size() < k) {
                for (int j : count[i]) breaks.push_back(j);
            }
        }

        if (breaks.size() == 1) return s.size();
        breaks.push_back(s.size());

        int result = 0;
        for (int i = 0; i < breaks.size() - 1; ++i) {
            int v = longestSubstring(
                s.substr(breaks[i] + 1, breaks[i + 1] - breaks[i] - 1), k);
            result = max(result, v);
        }

        return result;
    }
};
