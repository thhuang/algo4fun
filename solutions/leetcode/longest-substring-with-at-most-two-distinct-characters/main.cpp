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
