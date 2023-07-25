class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] == 9) continue;

            ++digits[i];
            for (int j = i + 1; j < n; ++j) {
                digits[j] = 0;
            }
            return digits;
        }
        digits.push_back(0);
        fill(digits.begin(), digits.end(), 0);
        digits[0] = 1;
        return digits;
    }
};

class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0 && carry == 1; --i) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        if (carry) digits.insert(digits.begin(), 1);
        return digits;
    }
};
