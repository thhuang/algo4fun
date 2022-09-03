class Solution {
   public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts,
                      long long budget) {
        int n = chargeTimes.size();

        int result = 0;

        deque<int> dec;
        long long sum = 0;
        for (int l = 0, r = 0; r < n; ++r) {
            while (!dec.empty() && dec.back() < chargeTimes[r]) dec.pop_back();
            dec.push_back(chargeTimes[r]);

            sum += runningCosts[r];

            while (l <= r && sum * (r - l + 1) + dec.front() > budget) {
                if (dec.front() == chargeTimes[l]) dec.pop_front();
                sum -= runningCosts[l];
                ++l;
            }

            result = max(result, r - l + 1);
        }

        return result;
    }
};
