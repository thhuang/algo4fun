class Solution {
    const int mod = 1e9 + 7;

   public:
    int numberOfWays(string corridor) {
        int n = corridor.size();

        vector<int> seatIndex;
        for (int i = 0; i < n; ++i) {
            if (corridor[i] == 'S') {
                seatIndex.push_back(i);
            }
        }
        if (seatIndex.empty() || seatIndex.size() % 2 != 0) return 0;

        int result = 1;
        seatIndex.pop_back();
        for (int i = 1; i < seatIndex.size(); i += 2) {
            int l = seatIndex[i];
            int r = seatIndex[i + 1];
            result = (long long)result * (r - l) % mod;
        }

        return result;
    }
};
