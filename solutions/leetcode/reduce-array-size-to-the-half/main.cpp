class Solution {
   public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> num2count;
        for (int v : arr) ++num2count[v];

        vector<int> counts;
        for (auto [_, count] : num2count) counts.push_back(count);
        sort(counts.begin(), counts.end());

        int v = 0, s = 0;
        for (int i = 0, s = 0; i < counts.size(); ++i) {
            s += counts[i];
            if (s > n / 2) break;
            ++v;
        }

        return counts.size() - v;
    }
};
