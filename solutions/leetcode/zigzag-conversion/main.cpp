class Solution {
   public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> rows(numRows);
        int r = 0, dir = 1;
        for (char c : s) {
            rows[r] += c;
            if (r + dir < 0 || numRows == r + dir) dir = -dir;
            r += dir;
        }
        return accumulate(rows.begin(), rows.end(), string());
    }
};
