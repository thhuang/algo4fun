class Solution {
   public:
    bool isNumber(string s) {
        regex rule(
            "([+-]?\\d+|[+-]?(\\d*\\.\\d+|\\d+\\.\\d*))([eE][+-]?\\d+)?");
        return regex_match(s, rule);
    }
};

class Solution {
    string integer = "([+-]?\\d+)";
    string decimal = "([+-]?(\\d*\\.\\d+|\\d+\\.\\d*))";
    string integerOrDecimal = "(" + integer + "|" + decimal + ")";
    string e = "([eE]" + integer + ")";
    string number = "(" + integerOrDecimal + e + "?" + ")";
    regex rule = regex(number);

   public:
    bool isNumber(string s) { return regex_match(s, rule); }
};
