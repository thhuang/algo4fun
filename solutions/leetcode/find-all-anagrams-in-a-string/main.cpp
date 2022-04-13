class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> char_count;
        for (char c : p) --char_count[c];

        vector<int> result;
        int k = p.size();
        int score = k;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];

            score -= abs(char_count[c]);
            ++char_count[c];
            score += abs(char_count[c]);

            if (i >= k) {
                char r = s[i - k];
                score -= abs(char_count[r]);
                --char_count[r];
                score += abs(char_count[r]);
            }

            if (score == 0) result.push_back(i - k + 1);
        }

        return result;
    }
};
