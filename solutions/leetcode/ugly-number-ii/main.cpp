class Solution {
    const vector<int> primes = {2, 3, 5};

   public:
    int nthUglyNumber(int n) {
        unordered_set<int> seen;
        priority_queue<int, vector<int>, greater<>> q;
        q.push(1);

        int ans;
        for (int i = 0; i < n; ++i) {
            ans = q.top();
            q.pop();
            seen.erase(ans);

            for (int p : primes) {
                if (ans > numeric_limits<int>::max() / p) continue;

                int num = ans * p;
                if (seen.count(num)) continue;

                seen.insert(num);
                q.push(num);
            }
        }

        return ans;
    }
};

class Solution {
    const vector<int> primes = {2, 3, 5};

   public:
    int nthUglyNumber(int n) {
        set<int> s;
        s.insert(1);

        int ans;
        for (int i = 0; i < n; ++i) {
            auto it = s.begin();
            ans = *it;
            s.erase(it);

            for (int p : primes) {
                if (ans > numeric_limits<int>::max() / p) continue;
                s.insert(ans * p);
            }
        }

        return ans;
    }
};

class Solution {
   public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; ++i) {
            int v = min({dp[p2] * 2, dp[p3] * 3, dp[p5] * 5});
            dp[i] = v;
            if (v == dp[p2] * 2) ++p2;
            if (v == dp[p3] * 3) ++p3;
            if (v == dp[p5] * 5) ++p5;
        }

        return dp.back();
    }
};
