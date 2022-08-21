class Solution {
   public:
    string largestPalindromic(string num) {
        array<int, 10> count;
        fill(count.begin(), count.end(), 0);
        for (char c : num) ++count[c - '0'];

        vector<int> single;
        vector<pair<int, int>> multiple;
        for (int i = 0; i < 10; ++i) {
            if (count[i] % 2 == 1) {
                --count[i];
                single.push_back(i);
            }
            if (count[i] > 0) {
                multiple.push_back({i, count[i] / 2});
            }
        }

        if (!multiple.empty() && multiple.back().first == 0) {
            if (single.empty()) return "0";
            return to_string(single.back());
        }

        string s;
        reverse(multiple.begin(), multiple.end());
        for (auto [i, cnt] : multiple) s += string(cnt, '0' + i);

        if (single.empty()) return s + string(s.rbegin(), s.rend());
        return s + to_string(single.back()) + string(s.rbegin(), s.rend());
    }
};
