class Solution {
   public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if (tokens.empty()) return 0;

        sort(tokens.begin(), tokens.end());
        if (tokens.front() > power) return 0;

        int result = 0;
        int score = 0;
        int l = 0, r = tokens.size() - 1;
        while (l <= r) {
            if (power >= tokens[l]) {
                result = max(result, ++score);
                power -= tokens[l++];
            } else {
                --score;
                power += tokens[r--];
            }
        }

        return result;
    }
};
