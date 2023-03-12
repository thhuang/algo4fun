class Solution {
   public:
    bool isNumber(string s) {
        regex rule(
            "([+-]?\\d+|[+-]?(\\d*\\.\\d+|\\d+\\.\\d*))([eE][+-]?\\d+)?");
        return regex_match(s, rule);
    }
};
