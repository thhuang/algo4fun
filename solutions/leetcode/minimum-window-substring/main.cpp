class Solution {
   public:
    string minWindow(string s, string t) {
        int count = t.size();
        unordered_map<char, int> char_count;
        for (char c : t) ++char_count[c];

        int start = 0;
        int length = numeric_limits<int>::max();
        for (int l = 0, r = 0; r < s.size(); ++r) {
            if (char_count.count(s[r]) && --char_count[s[r]] >= 0) --count;
            while (count == 0) {
                if (length > r - l + 1) {
                    length = r - l + 1;
                    start = l;
                }

                if (char_count.count(s[l]) && ++char_count[s[l]] > 0) ++count;
                ++l;
            }
        }

        if (length > s.size()) return "";
        return s.substr(start, length);
    }
};
