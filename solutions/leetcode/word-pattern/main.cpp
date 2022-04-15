class Solution {
   public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> c2str;
        unordered_map<string, char> str2c;
        stringstream ss(s);
        int i = 0;
        string str;
        while (ss >> str) {
            if (i == pattern.size()) return false;
            char c = pattern[i++];
            bool found_c = c2str.count(c);
            bool found_s = str2c.count(str);
            if (found_c ^ found_s) return false;
            if (!found_c && !found_s) {
                c2str[c] = str;
                str2c[str] = c;
                continue;
            }
            if (c2str[c] != str) return false;
        }
        return i == pattern.size();
    }
};
