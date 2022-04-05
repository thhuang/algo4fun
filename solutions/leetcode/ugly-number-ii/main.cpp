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
