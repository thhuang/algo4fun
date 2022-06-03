
class Solution {
    bool is_palindrome(const string& s) {
        int n = s.size();
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] != s[n - 1 - i]) return false;
        }
        return true;
    }

   public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> mp;
        for (int i = 0; i < words.size(); ++i) {
            string s(words[i].rbegin(), words[i].rend());
            mp.insert({s, i});
        }

        vector<vector<int>> result;

        if (auto it = mp.find(""); it != mp.end()) {
            for (int i = 0; i < words.size(); ++i) {
                const string& s = words[i];
                if (s == "" || !is_palindrome(s)) continue;
                result.push_back({i, it->second});
                result.push_back({it->second, i});
            }
        }

        for (int i = 0; i < words.size(); ++i) {
            const string& s = words[i];

            if (const auto it = mp.find(s); it != mp.end() && it->second != i)
                result.push_back({i, it->second});

            for (int d = 1; d < s.size(); ++d) {
                string l = s.substr(0, d);
                string r = s.substr(d, s.size() - d);

                if (auto it = mp.find(l);
                    it != mp.end() && is_palindrome(r) && it->second != i)
                    result.push_back({i, it->second});
                if (auto it = mp.find(r);
                    it != mp.end() && is_palindrome(l) && it->second != i)
                    result.push_back({it->second, i});
            }
        }

        return result;
    }
};
