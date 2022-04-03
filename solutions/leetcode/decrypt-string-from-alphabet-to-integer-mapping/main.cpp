class Solution {
   public:
    string freqAlphabets(string s) {
        string ans;
        for (int i = size(s) - 1; ~i; --i) {
            if (s[i] != '#') {
                ans += 'a' + s[i] - '1';
                continue;
            }
            ans += 'a' - 1 + stoi(s.substr(i - 2, 2));
            i -= 2;
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
