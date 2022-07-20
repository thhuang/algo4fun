class Solution {
   public:
    int calculate(string s) {
        int i = 0;
        int n = s.size();

        function<int()> process = [&]() -> int {
            vector<char> ops;
            vector<int> vals;
            int v = 0;
            while (i < n) {
                char c = s[i++];
                if (isdigit(c)) {
                    v = v * 10 + (c - '0');
                } else if (c == '(') {
                    v = process();
                } else if (c == ')') {
                    break;
                } else {
                    vals.push_back(v);
                    ops.push_back(c);
                    v = 0;
                }
            }
            vals.push_back(v);

            for (int i = 0; i < ops.size(); ++i) {
                if (ops[i] != '*' && ops[i] != '/') continue;

                if (ops[i] == '*') {
                    vals[i + 1] = vals[i] * vals[i + 1];
                } else {  // ops[i] == '/'
                    vals[i + 1] = vals[i] / vals[i + 1];
                }

                vals[i] = 0;

                ops[i] = '+';
                if (i != 0 && ops[i - 1] == '-') ops[i] = '-';
            }

            int result = vals.front();
            for (int i = 0; i < ops.size(); ++i) {
                result += ops[i] == '+' ? vals[i + 1] : -vals[i + 1];
            }

            return result;
        };

        return process();
    }
};
