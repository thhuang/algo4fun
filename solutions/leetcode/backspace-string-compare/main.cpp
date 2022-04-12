class Solution {
   public:
    bool backspaceCompare(string s, string t) {
        auto reduce = [](string str) -> string {
            string result;
            int backspace = 0;
            for (int i = str.size() - 1; ~i; --i) {
                if (str[i] == '#') {
                    ++backspace;
                    continue;
                }
                if (backspace > 0) {
                    --backspace;
                    continue;
                }
                result += str[i];
            }
            return {result.rbegin(), result.rend()};
        };
        return reduce(s) == reduce(t);
    }
};
