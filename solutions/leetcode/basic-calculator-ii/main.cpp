class Solution {
    struct Token {
        char typ;
        int val;
    };

    Token getNum(const string& s, int& i) {
        int v = 0;
        for (; isdigit(s[i]); ++i) {
            v = v * 10 + (s[i] - '0');
        }
        --i;
        return Token{'v', v};
    }

   public:
    int calculate(string s) {
        vector<Token> tokens;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') continue;
            if (isdigit(s[i])) {
                tokens.push_back(getNum(s, i));
            } else {
                tokens.push_back({s[i]});
            }
        }

        vector<Token> reduced_tokens;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i].typ == '*') {
                reduced_tokens.back().val *= tokens[++i].val;
            } else if (tokens[i].typ == '/') {
                reduced_tokens.back().val /= tokens[++i].val;
            } else {
                reduced_tokens.push_back(tokens[i]);
            }
        }

        int result = reduced_tokens.front().val;
        for (int i = 1; i < reduced_tokens.size(); ++i) {
            if (reduced_tokens[i].typ == '+') {
                result += reduced_tokens[++i].val;
            } else {  // reduced_tokens[i].typ == '-'
                result -= reduced_tokens[++i].val;
            }
        }

        return result;
    }
};
