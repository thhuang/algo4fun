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

class Solution {
   public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;
        vector<string> words;
        while (ss >> word) words.push_back(word);

        if (words.size() != pattern.size()) return false;

        unordered_map<char, string> c2str;
        unordered_map<string, char> str2c;
        for (int i = 0; i < words.size(); ++i) {
            char c = pattern[i];
            string str = words[i];
            if (c2str.count(c) != str2c.count(str)) return false;
            if (c2str.count(c) == 0) {
                c2str[c] = str;
                str2c[str] = c;
                continue;
            }
            if (c2str[c] != str || str2c[str] != c) return false;
        }

        return true;
    }
};
