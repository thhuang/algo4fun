class Solution {
   public:
    long long appealSum(string s) {
        int n = s.size();

        long long count = 0;
        unordered_map<char, deque<int>> chars;
        for (int i = 0; i < n; ++i) {
            chars[s[i]].push_back(i);
            count += chars.size();
        }
        for (auto& p : chars) p.second.push_back(n);

        long long result = count;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            count -= chars[c][1] - chars[c][0];
            chars[c].pop_front();
            result += count;
        }

        return result;
    }
};
