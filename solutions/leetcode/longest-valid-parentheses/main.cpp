class Solution {
   public:
    int longestValidParentheses(string s) {
        int result = 0;

        int opens = 0;
        for (int l = 0, r = 0; r < s.size(); ++r) {
            opens += s[r] == '(' ? 1 : -1;

            if (opens < 0) {
                l = r + 1;
                opens = 0;
            } else if (opens == 0) {
                result = max(result, r - l + 1);
            }
        }

        reverse(s.begin(), s.end());
        int closes = 0;
        for (int l = 0, r = 0; r < s.size(); ++r) {
            closes += s[r] == ')' ? 1 : -1;

            if (closes < 0) {
                l = r + 1;
                closes = 0;
            } else if (closes == 0) {
                result = max(result, r - l + 1);
            }
        }

        return result;
    }
};

class Solution {
   public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int result = 0;

        function<void(char)> search = [&](char open) {
            for (int l = 0, r = 0, c = 0; r < n; ++r) {
                c += s[r] == open ? 1 : -1;
                if (c < 0) {
                    c = 0;
                    l = r + 1;
                } else if (c == 0) {
                    result = max(result, r - l + 1);
                }
            }
        };

        search('(');
        reverse(s.begin(), s.end());
        search(')');

        return result;
    }
};
