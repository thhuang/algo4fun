class Solution {
   public:
    int minAddToMakeValid(string s) {
        int result = 0;

        int open = 0;
        for (char c : s) {
            if (c == '(') {
                ++open;
            } else {
                open = max(0, open - 1);
            }
        }

        int close = 0;
        for (char c : string{s.rbegin(), s.rend()}) {
            if (c == ')') {
                ++close;
            } else {
                close = max(0, close - 1);
            }
        }

        return open + close;
    }
};
