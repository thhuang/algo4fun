class Solution {
   public:
    int myAtoi(string s) {
        string num_str = "";
        bool is_pos = true;

        int l = 0;
        while (l < s.size() && !isdigit(s[l])) ++l;
        if (l > 0) {
            if (s[l - 1] == '-') is_pos = false;
            int n = l;
            if (s[l - 1] == '+' || s[l - 1] == '-') --n;
            for (int i = 0; i < n; ++i) {
                if (s[i] != ' ') return 0;
            }
        }

        bool found_first_digit = false;
        for (int i = l; i < s.size() && isdigit(s[i]); ++i) {
            if (!found_first_digit && s[i] == '0') continue;
            found_first_digit = true;
            num_str += s[i];
        }
        if (num_str.empty()) return 0;

        string upperbound = to_string(numeric_limits<int>::max());
        string lowerbound = to_string(numeric_limits<int>::min());

        if (is_pos) {
            if (num_str.size() > upperbound.size())
                return numeric_limits<int>::max();
            if (num_str.size() == upperbound.size() && num_str > upperbound)
                return numeric_limits<int>::max();
        } else {  // !is_pos
            if (num_str.size() + 1 > lowerbound.size())
                return numeric_limits<int>::min();
            if (num_str.size() + 1 == lowerbound.size() &&
                num_str > lowerbound.substr(1))
                return numeric_limits<int>::min();
        }

        int result = 0;
        for (char c : num_str) result = result * 10 - (c - '0');
        if (is_pos) result *= -1;

        return result;
    }
};

class Solution {
   public:
    int myAtoi(string s) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                s = s.substr(i);
                break;
            }
        }
        if (s.empty()) return 0;

        int sign = 1;
        if (s[0] == '-') sign = -1;

        string t;
        for (int i = s[0] == '-' || s[0] == '+' ? 1 : 0;
             i < s.size() && isdigit(s[i]); ++i)
            t += s[i];

        for (int i = 0; i < t.size(); ++i) {
            if (t[i] != '0') {
                t = t.substr(i);
                break;
            }
            if (i == t.size() - 1) return 0;
        }

        int n = 10;
        if (t.size() > n)
            return sign > 0 ? numeric_limits<int>::max()
                            : numeric_limits<int>::min();

        t = string(n - t.size(), '0') + t;
        if (sign > 0 && t > to_string(numeric_limits<int>::max()))
            return numeric_limits<int>::max();
        if (sign < 0 && t > to_string(numeric_limits<int>::min()).substr(1))
            return numeric_limits<int>::min();

        int v = 0;
        for (char c : t) v = v * 10 + sign * (c - '0');

        return v;
    }
};
