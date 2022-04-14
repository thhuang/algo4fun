class Solution {
   public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        string result;

        int i = num1.size() - 1;
        int j = num2.size() - 1;
        while (~i && ~j) {
            carry += (num1[i] - '0') + (num2[j] - '0');
            result += '0' + carry % 10;
            carry /= 10;
            --i, --j;
        }

        int k = ~i ? i : j;
        auto& num3 = ~i ? num1 : num2;
        while (~k) {
            carry += num3[k] - '0';
            result += '0' + carry % 10;
            carry /= 10;
            --k;
        }

        if (carry) result += '0' + carry;

        reverse(result.begin(), result.end());

        return result;
    }
};
