class Solution {
   public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        list<int> last_index = {-1, -1};
        unordered_map<char, list<int>::iterator> char_entry;

        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];

            if (auto it = char_entry.find(c); it != char_entry.end()) {
                last_index.erase(it->second);
            }
            last_index.push_back(i);
            char_entry[c] = --last_index.end();

            result = max(result, i - *(-- -- --last_index.end()));
        }

        return result;
    }
};

class Solution {
   public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> char_count;
        int result = 0;

        for (int l = 0, r = 0; r < s.size(); ++r) {
            ++char_count[s[r]];

            while (char_count.size() > 2) {
                if (--char_count[s[l]] == 0) char_count.erase(s[l]);
                ++l;
            }

            result = max(result, r - l + 1);
        }

        return result;
    }
};
