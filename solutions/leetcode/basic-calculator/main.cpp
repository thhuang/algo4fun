class Solution {
   public:
    int calculate(string s) {
        int sum = 0;
        vector<int> sign = {1};
        int local_sign = 1;
        int v = 0;
        for (char c : s) {
            if (c == ' ') {
                continue;
            }
            if (isdigit(c)) {
                v = v * 10 + (c - '0');
                continue;
            }
            sum += v * local_sign * sign.back();
            v = 0;

            if (c == '(') {
                sign.push_back(local_sign * sign.back());
                local_sign = 1;
            } else if (c == ')') {
                sign.pop_back();
                local_sign = 1;
            } else if (c == '+') {
                local_sign = 1;
            } else if (c == '-') {
                local_sign = -1;
            }
        }
        sum += v * local_sign * sign.back();

        return sum;
    }
};
