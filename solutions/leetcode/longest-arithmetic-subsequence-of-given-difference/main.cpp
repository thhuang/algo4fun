class Solution {
   public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();

        int result = 0;
        unordered_map<int, int> dp = {{arr[0], 1}};
        for (int i = 1; i < n; ++i) {
            int v = arr[i];
            int t = v - difference;

            int p = 1;
            if (auto it = dp.find(t); it != dp.end()) p += it->second;
            result = max(result, dp[v] = p);
        }

        return result;
    }
};
