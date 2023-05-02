class Solution {
   public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        int n = text.size();
        vector<vector<int>> result;

        for (int i = 0; i < n; ++i) {
            for (const string& word : words) {
                int m = word.size();
                if (i + m > n) continue;
                if (text.substr(i, m) != word) continue;
                result.push_back({i, i + m - 1});
            }
        }

        sort(result.begin(), result.end(),
             [](const vector<int>& a, const vector<int>& b) -> bool {
                 if (a[0] != b[0]) return a[0] < b[0];
                 return a[1] < b[1];
             });

        return result;
    }
};
