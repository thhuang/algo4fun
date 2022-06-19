class Solution {
   public:
    string greatestLetter(string s) {
        unordered_set<char> chars;
        for (char c : s) chars.insert(c);

        string result = "";
        for (char c : chars) {
            if (islower(c)) continue;
            if (chars.count(tolower(c)) == 0) continue;
            if (c > result[0]) result = c;
        }

        return result;
    }
};
