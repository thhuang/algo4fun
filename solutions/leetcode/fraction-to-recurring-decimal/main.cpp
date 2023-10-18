class Solution {
   public:
    string fractionToDecimal(int numerator, int denominator) {
        string s;

        if ((numerator < 0) ^ (denominator < 0) && numerator != 0) s += '-';
        long long numer = abs(numerator);
        long long denom = abs(denominator);

        s += to_string(numer / denom);
        numer = numer % denom * 10;

        string t;

        unordered_map<int, int> seen;
        for (int i = 0; numer != 0; ++i) {
            if (seen.count(numer) > 0) {
                int j = seen[numer];
                return s + '.' + t.substr(0, j) + '(' + t.substr(j) + ')';
            }
            seen[numer] = i;

            int v = numer / denom;
            numer = numer % denom * 10;

            t += '0' + v;
        }

        if (t.empty()) return s;
        return s + '.' + t;
    }
};
