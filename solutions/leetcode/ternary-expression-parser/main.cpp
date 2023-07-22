class Solution {
   public:
    string parseTernary(string expression) {
        int n = expression.size();

        vector<int> q;
        unordered_map<int, int> qc;
        for (int i = 0; i < n; ++i) {
            if (expression[i] == '?') {
                q.push_back(i);
            } else if (expression[i] == ':') {
                qc[q.back()] = i;
                q.pop_back();
            }
        }

        function<string(int)> parse = [&](int i) -> string {
            if (isdigit(expression[i]) || i + 1 == n || expression[i + 1] == ':')
                return expression.substr(i, 1);

            if (expression[i] == 'T') return parse(i + 2);
            return parse(qc[i + 1] + 1);
        };
        return parse(0);
    }
};
