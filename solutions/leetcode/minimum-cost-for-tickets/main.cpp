class Solution {
    array<int, 3> tickets = {1, 7, 30};

   public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<array<int, 3>> dp(366, {0, 0, 0});

        int d = 0;
        for (int i = 1; i <= 365; ++i) {
            if (d == days.size() || days[d] != i) {
                dp[i] = dp[i - 1];
                continue;
            }
            ++d;

            for (int k = 0; k < tickets.size(); ++k) {
                int j = i - tickets[k];
                int v = j <= 0 ? 0 : *min_element(dp[j].begin(), dp[j].end());
                dp[i][k] = v + costs[k];
            }
        }

        return *min_element(dp.back().begin(), dp.back().end());
    }
};

class Solution {
    array<int, 3> tickets = {1, 7, 30};

   public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();

        unordered_map<int, int> cache;
        function<int(int)> calculate = [&](int i) -> int {
            if (i < 0) return 0;
            if (cache.count(i)) return cache[i];

            int result = numeric_limits<int>::max();
            for (int k = 0; k < tickets.size(); ++k) {
                int t = tickets[k];
                int c = costs[k];

                int j = i - 1;
                while (j >= 0 && days[i] - t < days[j]) --j;
                result = min(result, calculate(j) + c);
            }

            return cache[i] = result;
        };

        return calculate(n - 1);
    }
};

class Solution {
    const vector<int> durations = {1, 7, 30};

   public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();

        vector<int> dp(n + 1, numeric_limits<int>::max());
        dp.back() = 0;
        for (int i = n - 1; ~i; --i) {
            for (int j = 0; j < costs.size(); ++j) {
                int c = dp[i + 1] + costs[j];
                for (int k = i; ~k && days[i] - days[k] < durations[j]; --k) {
                    dp[k] = min(dp[k], c);
                }
            }
        }

        return dp.front();
    }
};

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        const array<int, 3> passes = {1, 7, 30};

        int n = days.size();

        vector<int> dp(n + 1, numeric_limits<int>::max());
        dp.back() = 0;

        for (int l = n - 1; l >= 0; --l) {
            for (int i = 0; i < 3; ++i) {
                int d = passes[i];
                int c = costs[i];
                int r = lower_bound(days.begin(), days.end(), days[l] + d) - days.begin();
                dp[l] = min(dp[l], dp[r] + c);
            }
        }

        return dp.front();
    }
};
