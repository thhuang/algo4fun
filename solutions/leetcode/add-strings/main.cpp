class Solution {
   public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        string result;

        int i = num1.size() - 1;
        int j = num2.size() - 1;
        while (~i || ~j) {
            if (~i) carry += num1[i--] - '0';
            if (~j) carry += num2[j--] - '0';
            result += '0' + carry % 10;
            carry /= 10;
        }

        if (carry) result += '0' + carry;

        reverse(result.begin(), result.end());

        return result;
    }
};
