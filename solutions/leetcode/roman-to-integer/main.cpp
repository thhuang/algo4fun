class Solution {
    unordered_map<char, int> mp = {{'I', 1},   {'V', 5},   {'X', 10},
                                   {'L', 50},  {'C', 100}, {'D', 500},
                                   {'M', 1000}};

   public:
    int romanToInt(string s) {
        int result;
        for (int i = 0; i < s.size(); ++i) {
            int sign = 1;
            if (i < s.size() - 1 && mp[s[i]] < mp[s[i + 1]]) sign = -1;
            result += mp[s[i]] * sign;
        }
        return result;
    }
};
