class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        vector<array<int, 2>> temperature_index;
        for (int i = 0; i < n; ++i) {
            while (!temperature_index.empty() &&
                   temperature_index.back()[0] < temperatures[i]) {
                int j = temperature_index.back()[1];
                temperature_index.pop_back();
                result[j] = i - j;
            }
            temperature_index.push_back({temperatures[i], i});
        }
        return result;
    }
};

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        int max_t = 0;
        for (int i = n - 1; ~i; --i) {
            int t = temperatures[i];
            if (t >= max_t) {
                max_t = t;
                continue;
            }

            int d = 1;
            while (temperatures[i] >= temperatures[i + d]) {
                d += result[i + d];
            }
            result[i] = d;
        }
        return result;
    }
};
