class Solution {
    const int mod = 1e9 + 7;

   public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        deque<long long> delaying(delay, 0);
        deque<long long> sharing(forget - delay, 0);

        delaying.back() = 1;

        long long count = 0;
        for (int i = 1; i < n; ++i) {
            count = (count - sharing.front()) % mod;
            sharing.pop_front();
            sharing.push_back(delaying.front());
            count = (count + sharing.back()) % mod;

            delaying.push_back(count);
            delaying.pop_front();
        }

        long long result = 0;
        for (int v : delaying) result = (result + v) % mod;
        for (int v : sharing) result = (result + v) % mod;

        result = (result + mod) % mod;
        return result;
    }
};
