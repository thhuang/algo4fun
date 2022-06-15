class Solution {
   public:
    string shortestPalindrome(string s) {
        auto check = [&](int r) -> bool {
            for (int i = 0; i < r / 2 + 1; ++i) {
                if (s[i] != s[r - i]) return false;
            }
            return true;
        };

        for (int i = s.size() - 1; ~i; --i) {
            if (check(i)) {
                string result = s.substr(i + 1);
                reverse(result.begin(), result.end());
                return result + s;
            }
        }

        return "";
    }
};

class Solution {
   public:
    string shortestPalindrome(string s) {
        int n = s.size();
        string r(s.rbegin(), s.rend());
        for (int i = 0; i < n; ++i) {
            if (s.compare(0, n - i, r, i, n) == 0) {
                return r.substr(0, i) + s;
            }
        }

        return "";
    }
};

class Solution {
   public:
    string shortestPalindrome(string s) {
        string r(s.rbegin(), s.rend());

        string sr = s + ":" + r;
        vector<int> prefix(sr.size(), 0);

        for (int i = 1; i < sr.size(); ++i) {
            int d = prefix[i - 1];
            while (d > 0 && sr[i] != sr[d]) d = prefix[d - 1];
            if (sr[i] == sr[d]) ++d;
            prefix[i] = d;
        }

        return r.substr(0, r.size() - prefix.back()) + s;
    }
};
