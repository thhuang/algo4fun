class Solution {
   public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> char_order;
        for (int i = 0; i < size(order); ++i) char_order[order[i]] = i;

        auto less_than_or_equal_to = [&](const string& a,
                                         const string& b) -> bool {
            for (int i = 0; i < size(a) && i < size(b); ++i) {
                if (char_order[a[i]] < char_order[b[i]]) return true;
                if (char_order[a[i]] > char_order[b[i]]) return false;
            }
            return size(a) <= size(b);
        };

        for (int i = 0; i < size(words) - 1; ++i) {
            if (!less_than_or_equal_to(words[i], words[i + 1])) return false;
        }

        return true;
    }
};
