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
