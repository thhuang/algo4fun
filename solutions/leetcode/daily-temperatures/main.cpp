class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        vector<array<int, 2>> temperature_index;
        for (int i = 0; i < n; ++i) {
            while (!temperature_index.empty() &&
                   temperature_index.back()[0] < temperatures[i]) {
                auto [_, j] = temperature_index.back();
                temperature_index.pop_back();
                result[j] = i - j;
            }
            temperature_index.push_back({temperatures[i], i});
        }
        return result;
    }
};
