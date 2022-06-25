class Solution {
   public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int k = digits.size();

        vector<int> nums;
        for (const string& s : digits) nums.push_back(stoi(s));

        int upper = 10;
        while (upper < n) upper *= 10;

        long long result = 0;
        for (long long i = 1, j = k; i < upper; i *= 10, j *= k) {
            result += j;
        }

        if (upper == n) return result;

        long long over = 0;
        for (int i = n, j = 1; i; i /= 10, j *= k) {
            int v = i % 10;
            long long new_over = 0;
            for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
                if (*it < v) break;
                if (*it == v) {
                    new_over += over;
                } else {
                    new_over += j;
                }
            }
            over = new_over;
        }

        return result - over;
    }
};
