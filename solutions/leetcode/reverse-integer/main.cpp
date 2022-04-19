class Solution {
   public:
    int reverse(int x) {
        bool is_pos = x >= 0;
        string upperbound = to_string(numeric_limits<int>::max());
        string lowerbound = to_string(numeric_limits<int>::min());

        string s = to_string(x);
        ::reverse(s.begin(), s.end());
        if (is_pos && s.size() == upperbound.size() && s > upperbound) return 0;
        if (!is_pos && s.size() == lowerbound.size() &&
            s.substr(0, s.size() - 1) > lowerbound.substr(1))
            return 0;

        int result = 0;
        for (char c : s) {
            if (c == '-') continue;
            result = result * 10 - (c - '0');
        }

        if (is_pos) result *= -1;
        return result;
    }
};
