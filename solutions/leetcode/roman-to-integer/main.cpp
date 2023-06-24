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

class Solution {
    int mp(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }

   public:
    int romanToInt(string s) {
        int n = s.size();
        int result = 0;
        for (int i = n - 1; i >= 0; --i) {
            int v = mp(s[i]);
            if (i + 1 < n && v < mp(s[i + 1])) v = -v;
            result += v;
        }
        return result;
    }
};
