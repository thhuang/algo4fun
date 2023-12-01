class Solution {
   public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1, s2;
        for (const string& w : word1) s1 += w;
        for (const string& w : word2) s2 += w;
        return s1 == s2;
    }
};

class Solution {
   public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int vi = 0, vj = 0, i = 0, j = 0;
        while (true) {
            if (i == word1[vi].size()) ++vi, i = 0;
            if (j == word2[vj].size()) ++vj, j = 0;
            if (vi == word1.size() || vj == word2.size()) break;
            if (word1[vi][i++] != word2[vj][j++]) return false;
        }
        return vi == word1.size() && vj == word2.size();
    }
};
