class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int v = x;
        int left_pos = 1;
        int count = 1;
        while (v /= 10) left_pos *= 10, ++count;

        int right_pos = 1;
        for (int i = 0; i < count / 2; ++i, left_pos /= 10, right_pos *= 10) {
            int left = (x / left_pos) % 10;
            int right = (x / right_pos) % 10;
            if (left != right) return false;
        }

        return true;
    }
};

class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long long y = 0;
        for (int v = x; v; v /= 10) {
            y = y * 10 + v % 10;
        }
        return x == y;
    }
};
