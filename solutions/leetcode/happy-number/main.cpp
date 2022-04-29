class Solution {
   public:
    bool isHappy(int n) {
        unordered_set<int> vis;
        while (n != 1) {
            if (vis.count(n)) return false;
            vis.insert(n);

            int m = 0;
            while (n) {
                int digit = n % 10;
                m += digit * digit;
                n /= 10;
            }
            n = m;
        }
        return true;
    }
};

class Solution {
    int nextNum(int n) {
        int sum = 0;
        while (n) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

   public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        while (true) {
            fast = nextNum(nextNum(fast));
            slow = nextNum(slow);
            if (fast == 1 || slow == fast) break;
        }
        return fast == 1;
    }
};
