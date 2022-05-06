class Solution {
   public:
    string removeDuplicates(string s, int k) {
        struct CharCount {
            char c;
            int count;
        };

        vector<CharCount> char_count;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (char_count.empty() || char_count.back().c != c) {
                char_count.push_back({c, 1});
            } else {
                ++char_count.back().count;
            }
            if (!char_count.empty() && char_count.back().count == k)
                char_count.pop_back();
        }

        string result;
        for (auto cc : char_count) {
            while (cc.count--) result += cc.c;
        }

        return result;
    }
};

class Solution {
   public:
    string removeDuplicates(string s, int k) {
        vector<tuple<char, int>> dups;
        for (char c : s) {
            if (dups.empty() || get<char>(dups.back()) != c) {
                dups.push_back({c, 1});
            } else {
                ++get<int>(dups.back());
            }
            if (!dups.empty() && get<int>(dups.back()) == k) dups.pop_back();
        }

        string result;
        for (auto [c, i] : dups) {
            while (i--) result += c;
        }
        return result;
    }
};
