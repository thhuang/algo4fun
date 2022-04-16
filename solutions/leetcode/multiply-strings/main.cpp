class Solution {
   public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int n1 = num1.size();
        int n2 = num2.size();
        vector<int> product(n1 + n2, 0);

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for (int i = 0; i < n1; ++i) {
            int carry = 0;
            for (int j = 0; j < n2; ++j) {
                int v1 = num1[i] - '0';
                int v2 = num2[j] - '0';
                product[i + j] += carry + v1 * v2;
                carry = product[i + j] / 10;
                product[i + j] %= 10;
            }
            if (carry) product[i + n2] += carry;
        }

        if (product.back() == 0) product.pop_back();
        reverse(product.begin(), product.end());

        string result;
        for (int v : product) result.push_back('0' + v);

        return result;
    }
};
