class Solution {
   public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        reverse(arr1.begin(), arr1.end());
        reverse(arr2.begin(), arr2.end());

        vector<int> rresult;
        for (int i = 0, carry1 = 0, carry2 = 0;
             i < arr1.size() || i < arr2.size() || carry1 || carry2; ++i) {
            int v = carry1;
            carry1 = carry2, carry2 = 0;

            if (i < arr1.size()) v += arr1[i];
            if (i < arr2.size()) v += arr2[i];

            rresult.push_back(v % 2);
            carry1 += v / 2;
            carry2 += v / 2;
            while (carry2 >= 1 && carry1 >= 2) carry2 -= 1, carry1 -= 2;
        }

        while (rresult.size() > 1 && rresult.back() == 0) rresult.pop_back();

        return {rresult.rbegin(), rresult.rend()};
    }
};
