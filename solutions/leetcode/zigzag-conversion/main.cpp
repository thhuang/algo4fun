class Solution {
   public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> rows(numRows);
        int i = 0;
        int dir = 1;
        for (char c : s) {
            rows[i] += c;
            if (i + dir < 0 || i + dir == numRows) dir = -dir;
            i += dir;
        }
        string result;
        for (string r : rows) result += r;
        return result;
    }
};
