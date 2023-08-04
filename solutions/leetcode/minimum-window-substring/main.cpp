class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> target;
        for (char c : t) ++target[c];

        unordered_map<char, int> mp;
        auto check = [&]() -> bool {
            for (auto [c, v] : target) {
                if (mp[c] < v) return false;
            }
            return true;
        };

        pair<int, int> result = {-1, numeric_limits<int>::max()};
        for (int r = 0, l = 0; r < s.size(); ++r) {
            ++mp[s[r]];
            while (check()) {
                if (r - l + 1 < result.second) {
                    result = {l, r - l + 1};
                }
                --mp[s[l++]];
            }
        }

        if (result.first == -1) return "";
        return s.substr(result.first, result.second);
    }
};

class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> target;
        for (char c : t) ++target[c];
        int count = t.size();

        pair<int, int> result = {-1, numeric_limits<int>::max()};
        unordered_map<char, int> mp;
        for (int r = 0, l = 0; r < s.size(); ++r) {
            if (++mp[s[r]] <= target[s[r]]) --count;
            for (; count == 0; ++l) {
                if (r - l + 1 < result.second) {
                    result = {l, r - l + 1};
                }
                if (mp[s[l]]-- <= target[s[l]]) ++count;
            }
        }

        if (result.first == -1) return "";
        return s.substr(result.first, result.second);
    }
};

class Solution {
   public:
    string minWindow(string s, string t) {
        int n = t.size();

        unordered_map<char, int> want;
        for (char c : t) ++want[c];

        array<int, 2> result = {-1, (int)s.size()};
        for (int l = 0, r = 0; r < s.size(); ++r) {
            if (--want[s[r]] >= 0) --n;
            while (n <= 0) {
                if (r - l < result[1] - result[0]) result = {l, r};
                if (++want[s[l++]] > 0) ++n;
            }
        }

        int sz = result[1] - result[0] + 1;
        return sz > s.size() ? "" : s.substr(result[0], sz);
    }
};

class Solution {
   public:
    string minWindow(string s, string t) {
        int n = t.size();
        unordered_map<char, int> want;
        for (char c : t) ++want[c];

        array<int, 2> result = {-1, -1};
        for (int l = 0, r = 0; r < s.size(); ++r) {
            if (want.count(s[r]) == 0) continue;

            if (--want[s[r]] >= 0) --n;
            while (n == 0) {
                if (result[0] == -1 || r - l < result[1] - result[0])
                    result = {l, r};
                if (want.count(s[l]) != 0 && ++want[s[l]] > 0) ++n;
                ++l;
            }
        }

        return result[0] == -1 ? ""
                               : s.substr(result[0], result[1] - result[0] + 1);
    }
};
