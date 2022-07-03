class Solution {
   public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> mp;
        mp[' '] = ' ';

        char p = 'a';
        for (char c : key) {
            if (c == ' ') continue;
            if (mp.count(c)) continue;
            mp[c] = p++;
        }

        string result;
        for (char c : message) result.push_back(mp[c]);

        return result;
    }
};
