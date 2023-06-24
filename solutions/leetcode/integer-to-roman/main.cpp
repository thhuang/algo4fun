class Solution {
    const vector<string> one = {"",  "I",  "II",  "III",  "IV",
                                "V", "VI", "VII", "VIII", "IX"};
    const vector<string> ten = {"",  "X",  "XX",  "XXX",  "XL",
                                "L", "LX", "LXX", "LXXX", "XC"};
    const vector<string> hundred = {"",  "C",  "CC",  "CCC",  "CD",
                                    "D", "DC", "DCC", "DCCC", "CM"};
    const vector<string> thousand = {"", "M", "MM", "MMM"};

   public:
    string intToRoman(int num) {
        return thousand[num / 1000] + hundred[num % 1000 / 100] +
               ten[num % 100 / 10] + one[num % 10];
    }
};

class Solution {
    string helper(int v, char ten, char five, char one) {
        string result;
        if (v == 9) {
            result += one;
            result += ten;
        } else if (v == 4) {
            result += one;
            result += five;
        } else {
            if (v >= 5) result += five;
            result += string(v % 5, one);
        }
        return result;
    }

   public:
    string intToRoman(int num) {
        string result;
        result += string(num / 1000, 'M');
        num %= 1000;
        result += helper(num / 100, 'M', 'D', 'C');
        num %= 100;
        result += helper(num / 10, 'C', 'L', 'X');
        num %= 10;
        result += helper(num, 'X', 'V', 'I');
        return result;
    }
};
