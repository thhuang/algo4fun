class Solution {
    const int mod = 1e9 + 7;

   public:
    int countTexts(string pressedKeys) {
        long long result = 1;

        auto process = [&](char c, long long count) -> void {
            if (c != '7' && c != '9') {
                array<long long, 3> dp = {1, 2, 4};
                if (count <= 3) {
                    result = (result * dp[count - 1]) % mod;
                    return;
                }
                for (int i = 4; i <= count; ++i)
                    dp = {dp[1], dp[2], (dp[0] + dp[1] + dp[2]) % mod};
                result = (result * dp.back()) % mod;
            } else {
                array<long long, 4> dp = {1, 2, 4, 8};
                if (count <= 4) {
                    result = (result * dp[count - 1]) % mod;
                    return;
                }
                for (int i = 5; i <= count; ++i)
                    dp = {dp[1], dp[2], dp[3],
                          (dp[0] + dp[1] + dp[2] + dp[3]) % mod};
                result = (result * dp.back()) % mod;
            }
        };

        long long count = 1;
        char curr = pressedKeys.front();
        for (int i = 1; i < pressedKeys.size(); ++i) {
            char c = pressedKeys[i];
            if (c == curr) {
                ++count;
                continue;
            }

            process(curr, count);
            curr = c;
            count = 1;
        };
        process(curr, count);

        return result;
    }
};
