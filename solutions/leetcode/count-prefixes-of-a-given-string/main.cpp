class Solution {
   public:
    int countPrefixes(vector<string>& words, string s) {
        unordered_set<string> valid;
        string prefix;
        for (int i = 0; i < s.size(); ++i) {
            prefix += s[i];
            valid.insert(prefix);
        }
        int count = 0;
        for (string w : words) {
            if (valid.count(w)) ++count;
        }
        return count;
    }
};

class Solution {
   public:
    int countPrefixes(vector<string>& words, string s) {
        unordered_map<string, int> valid;
        for (string w : words) ++valid[w];

        int count = 0;
        string prefix;
        for (int i = 0; i < s.size(); ++i) {
            count += valid[prefix += s[i]];
        }

        return count;
    }
};

class Solution {
   public:
    int countPrefixes(vector<string>& words, string s) {
        int count = 0;
        for (string w : words) {
            if (s.substr(0, w.size()) == w) ++count;
        }
        return count;
    }
};
