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
