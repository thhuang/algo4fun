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
