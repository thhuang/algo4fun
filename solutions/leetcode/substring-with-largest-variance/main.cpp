// https://leetcode.com/problems/substring-with-largest-variance/discuss/2039178/Weird-Kadane
class Solution {
   public:
    int largestVariance(string s) {
        unordered_set<char> chars(s.begin(), s.end());

        int result = 0;
        for (char a : chars) {
            for (char b : chars) {
                if (a == b) continue;

                int var = 0;
                bool seen_b = false, b_is_first = false;
                for (char c : s) {
                    if (c == a) ++var;
                    if (c == b) {
                        seen_b = true;

                        if (b_is_first && var >= 0) {
                            b_is_first = false;
                        } else if (--var < 0) {
                            b_is_first = true;
                            var = -1;
                        }
                    }

                    if (seen_b) result = max(result, var);
                }
            }
        }

        return result;
    }
};
