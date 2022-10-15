class Solution {
   public:
    int countTime(string time) {
        int result = 1;

        string hh = time.substr(0, 2);
        if (hh == "??") {
            result *= 24;
        } else if (hh[0] == '?') {
            string h = hh;
            int cnt = 0;
            for (char c = '0'; c <= '9'; ++c) {
                if (h[0] = c; stoi(h) <= 23) ++cnt;
            }
            result *= cnt;
        } else if (hh[1] == '?') {
            string h = hh;
            int cnt = 0;
            for (char c = '0'; c <= '9'; ++c) {
                if (h[1] = c; stoi(h) <= 23) ++cnt;
            }
            result *= cnt;
        }

        string mm = time.substr(3, 2);
        if (mm == "??") {
            result *= 60;
        } else if (mm[0] == '?') {
            string m = mm;
            int cnt = 0;
            for (char c = '0'; c <= '9'; ++c) {
                if (m[0] = c; stoi(m) <= 59) ++cnt;
            }
            result *= cnt;
        } else if (mm[1] == '?') {
            string m = mm;
            int cnt = 0;
            for (char c = '0'; c <= '9'; ++c) {
                if (m[1] = c; stoi(m) <= 59) ++cnt;
            }
            result *= cnt;
        }

        return result;
    }
};
