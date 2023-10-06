class Solution {
    typedef long long ll;

    const string numericOps = "+-*";

   public:
    vector<string> addOperators(string num, int target) {
        int n = num.size();
        vector<string> result;

        function<void(int, ll, ll, string)> search =
            [&](int i, ll value, ll lastValue, string s) -> void {
            if (i == n) {
                if (value + lastValue == target) {
                    result.push_back(s);
                }
                return;
            }

            for (char op : numericOps) {
                if (op != '+' && i == 0) continue;

                string ss = s;
                if (i > 0) ss += op;

                ll v = 0;
                for (int j = i; j < n; ++j) {
                    ss += num[j];
                    v = v * 10 + num[j] - '0';

                    if (to_string(v).size() != j - i + 1) break;

                    switch (op) {
                        case '+': {
                            search(j + 1, value + lastValue, v, ss);
                            break;
                        }
                        case '-': {
                            search(j + 1, value + lastValue, -v, ss);
                            break;
                        }
                        case '*': {
                            search(j + 1, value, lastValue * v, ss);
                            break;
                        }
                    }
                }
            }
        };

        search(0, 0, 0, "");

        return result;
    }
};
