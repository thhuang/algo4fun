class Solution {
   public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(), num.end());

        vector<int> rresult;
        for (int i = 0, carry = 0; i < num.size() || k || carry; ++i) {
            int a = 0;
            if (i < num.size()) a = num[i];

            int b = k % 10;
            k /= 10;

            carry += a + b;
            rresult.push_back(carry % 10);
            carry /= 10;
        }

        return {rresult.rbegin(), rresult.rend()};
    }
};

class Solution {
   public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> rresult;
        for (int i = 0, carry = 0; i < num.size() || k || carry; ++i) {
            int a = 0;
            if (i < num.size()) a = *(num.rbegin() + i);

            int b = k % 10;
            k /= 10;

            carry += a + b;
            rresult.push_back(carry % 10);
            carry /= 10;
        }

        return {rresult.rbegin(), rresult.rend()};
    }
};
