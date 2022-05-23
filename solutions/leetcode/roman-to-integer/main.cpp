class Solution {
    const unordered_map<char, int> char2num = {
        {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}};

    bool shouldMinus(char curr, char next) {
        switch (curr) {
            case 'I':
                return next == 'V' || next == 'X';
            case 'X':
                return next == 'L' || next == 'C';
            case 'C':
                return next == 'D' || next == 'M';
        }
        return false;
    }

   public:
    int romanToInt(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            int v = char2num.at(s[i]);
            if (i + 1 < s.size() && shouldMinus(s[i], s[i + 1])) v = -v;
            result += v;
        }
        return result;
    }
};

class Solution {
    const unordered_map<char, int> char2num = {
        {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}};

   public:
    int romanToInt(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            int v = char2num.at(s[i]);
            if (i + 1 < s.size() && v < char2num.at(s[i + 1])) v = -v;
            result += v;
        }
        return result;
    }
};
