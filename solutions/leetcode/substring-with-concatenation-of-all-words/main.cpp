class Solution {
   public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int sz = words.front().size();
        int n = sz * words.size();

        unordered_map<string, int> want;
        for (const string& w : words) ++want[w];

        function<bool(int)> check = [&](int i) -> bool {
            auto got = want;
            for (int j = 0; j < words.size(); ++j) {
                string w = s.substr(i + j * sz, sz);
                if (--got[w] < 0) return false;
            }
            return true;
        };

        vector<int> result;
        for (int i = 0; i + n <= s.size(); ++i) {
            if (check(i)) result.push_back(i);
        }

        return result;
    }
};
