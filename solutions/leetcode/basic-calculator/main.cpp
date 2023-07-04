class Solution {
   public:
    int calculate(string s) {
        int sum = 0;
        vector<int> sign = {1};
        int local_sign = 1;
        int v = 0;
        for (char c : s) {
            if (c == ' ') continue;
            if (isdigit(c)) {
                v = v * 10 + (c - '0');
                continue;
            }

            sum += v * local_sign * sign.back();
            v = 0;

            if (c == '+') {
                local_sign = 1;
            } else if (c == '-') {
                local_sign = -1;
            } else if (c == '(') {
                sign.push_back(local_sign * sign.back());
                local_sign = 1;
            } else {  // c == ')'
                sign.pop_back();
            }
        }

        return sum += v * local_sign * sign.back();
    }
};

class Solution {
    int eval(string& s, int& i) {
        vector<int> nums;
        int sign = 1;
        for (; i < s.size() && s[i] != ')'; ++i) {
            if (s[i] == ' ' || s[i] == '+') {
                continue;
            } else if (s[i] == '(') {
                nums.push_back(sign * eval(s, ++i));
                sign = 1;
            } else if (s[i] == '-') {
                sign *= -1;
            } else {  // digit
                int v = 0;
                for (; i < s.size() && isdigit(s[i]); ++i)
                    v = v * 10 + (s[i] - '0');
                --i;
                nums.push_back(sign * v);
                sign = 1;
            }
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }

   public:
    int calculate(string s) {
        int i = 0;
        return eval(s, i);
    }
};
