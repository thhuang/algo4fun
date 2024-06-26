class Solution {
   public:
    bool isHappy(int n) {
        unordered_map<int, bool> seen;
        while (n != 1) {
            int sum = 0;
            while (n) {
                int v = n % 10;
                sum += v * v;
                n /= 10;
            }
            n = sum;
            if (seen[n]) return false;
            seen[n] = true;
        }
        return true;
    }
};

class Solution {
    int next(int n) {
        int result = 0;
        while (n) {
            int v = n % 10;
            result += v * v;
            n /= 10;
        }
        return result;
    }

   public:
    bool isHappy(int n) {
        unordered_set<int> vis;
        while (vis.count(n) == 0 && n != 1) {
            vis.insert(n);
            n = next(n);
        }
        return n == 1;
    }
};

class Solution {
    int next(int v) {
        int result = 0;
        while (v) {
            int d = v % 10;
            v /= 10;
            result += d * d;
        }
        return result;
    }

   public:
    bool isHappy(int n) {
        int slow = n, fast = next(n);
        while (fast != 1 && slow != fast) {
            slow = next(slow);
            fast = next(next(fast));
        }
        return fast == 1;
    }
};

class Solution {
    int next(int n) {
        int result = 0;
        while (n) {
            int v = n % 10;
            result += v * v;
            n /= 10;
        }
        return result;
    }

   public:
    bool isHappy(int n) {
        int slow = n, fast = next(n);
        while (slow != fast) {
            slow = next(slow);
            fast = next(next(fast));
        }
        return slow == 1;
    }
};
