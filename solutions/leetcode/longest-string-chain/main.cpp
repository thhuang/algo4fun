class Solution {
   public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> cache;
        unordered_map<int, unordered_set<string>> length_words;

        int max_length = 1;
        for (string s : words) {
            int l = s.size();
            length_words[l].insert(s);
            max_length = max(max_length, l);
        }

        function<int(string, int)> dfs = [&](string s, int depth) -> int {
            if (length_words[s.size()].count(s) == 0) return depth - 1;
            if (auto it = cache.find(s); it != cache.end()) return it->second;

            int max_depth = depth;
            for (int i = 0; i < s.size(); ++i) {
                string candidate;
                for (int j = 0; j < s.size(); ++j) {
                    if (j == i) continue;
                    candidate += s[j];
                }
                max_depth = max(max_depth, dfs(candidate, depth + 1));
            }

            return cache[s] = max_depth;
        };

        int result = 0;
        for (int i = max_length; i >= 1; --i) {
            for (string s : length_words[i]) result = max(result, dfs(s, 1));
        }

        return result;
    }
};
