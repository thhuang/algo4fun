class Solution {
   public:
    vector<vector<string>> partition(string s) {
        int n = s.size();

        unordered_map<int, unordered_map<int, string>> cache;
        auto is_palindrome = [&](int i, int d) -> pair<string, bool> {
            if (auto it = cache[i].find(d); it != cache[i].end()) {
                return {it->second, it->second != ""};
            }

            for (int j = 0; j < d / 2; ++j) {
                if (s[i + j] != s[i + d - 1 - j]) {
                    return {cache[i][d] = "", false};
                }
            }
            return {cache[i][d] = s.substr(i, d), true};
        };

        vector<vector<string>> result;
        vector<string> curr;
        function<void(int)> search = [&](int i) -> void {
            if (i == n) {
                result.push_back(curr);
                return;
            }

            for (int d = 1; i + d <= n; ++d) {
                auto [sub, ok] = is_palindrome(i, d);
                if (!ok) continue;

                curr.push_back(sub);
                search(i + d);
                curr.pop_back();
            }
        };

        search(0);

        return result;
    }
};

class Solution {
   public:
    bool isPalindrome(string &s) {
        auto it = s.begin();
        auto rit = s.rbegin();
        for (int i = 0; i < s.size() / 2; ++i, ++it, ++rit) {
            if (*it != *rit) return false;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;

        vector<string> curr;
        function<void(int)> search = [&](int l) -> void {
            if (l == s.size()) {
                result.push_back(curr);
                return;
            }

            string ss;
            for (int r = l; r < s.size(); ++r) {
                ss += s[r];
                if (!isPalindrome(ss)) continue;

                curr.push_back(ss);
                search(r + 1);
                curr.pop_back();
            }
        };

        search(0);

        return result;
    }
};
