class Solution {
   public:
    bool isStrobogrammatic(string num) {
        array<int, 10> pairs = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
        for (int i = 0; i < (num.size() + 1) / 2; ++i) {
            if (pairs[num[i] - '0'] == -1) return false;
            if (pairs[num[i] - '0'] != num[num.size() - 1 - i] - '0')
                return false;
        }
        return true;
    }
};
