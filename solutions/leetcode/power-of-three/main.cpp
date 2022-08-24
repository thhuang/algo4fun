unordered_set<int> valid;

class Solution {
   public:
    bool isPowerOfThree(int n) {
        if (valid.empty()) {
            long long v = 1;
            while (v <= numeric_limits<int>::max()) {
                valid.insert(v);
                v *= 3;
            }
        }

        return valid.count(n);
    }
};
