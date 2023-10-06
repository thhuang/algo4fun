class Solution {
    typedef long long ll;

   public:
    vector<string> addOperators(string num, int target) {
        int n = num.size();
        vector<string> result;

        function<void(int, ll, ll, string)> search =
            [&](int i, ll value, ll lastValue, const string& s) -> void {
            if (i == n) {
                if (value + lastValue == target) {
                    result.push_back(s);
                }
                return;
            }

            ll v = 0;
            string sv;
            for (int j = i; j < n; ++j) {
                if (num[i] == '0' && j > i) break;

                v = v * 10 + num[j] - '0';
                sv += num[j];

                if (i == 0) {
                    search(j + 1, value + lastValue, v, sv);
                    continue;
                }

                search(j + 1, value + lastValue, v, s + '+' + sv);
                search(j + 1, value + lastValue, -v, s + '-' + sv);
                search(j + 1, value, lastValue * v, s + '*' + sv);
            }
        };

        search(0, 0, 0, "");

        return result;
    }
};
