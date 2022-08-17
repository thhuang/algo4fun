class Solution {
    const vector<string> morse = {
        ".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
        ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
        "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--.."};

   public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> patterns;

        for (const string& w : words) {
            string s;
            for (const char& c : w) s += morse[c - 'a'];
            patterns.insert(s);
        }

        return patterns.size();
    }
};
