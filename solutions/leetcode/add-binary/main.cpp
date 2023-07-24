class Solution {
   public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string result;
        for (int i = 0; i < a.size() || i < b.size(); ++i) {
            int v = 0;
            if (i < result.size()) {
                ++v;
            } else {
                result += '0';
            }
            if (i < a.size() && a[i] == '1') ++v;
            if (i < b.size() && b[i] == '1') ++v;
            if (v == 1) {
                result[i] = '1';
            } else if (v == 2) {
                result[i] = '0';
                result += '1';
            } else if (v == 3) {
                result[i] = '1';
                result += '1';
            }
        }

        return {result.rbegin(), result.rend()};
    }
};

class Solution {
   public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;

        string result;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0) carry += a[i--] == '1';
            if (j >= 0) carry += b[j--] == '1';
            result += to_string(carry & 1);
            carry >>= 1;
        }

        return {result.rbegin(), result.rend()};
    }
};
