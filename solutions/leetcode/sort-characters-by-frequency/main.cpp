class Solution {
   public:
    string frequencySort(string s) {
        unordered_map<char, int> char_count;
        for (char c : s) ++char_count[c];

        vector<char> chars(char_count.size());
        for (auto p : char_count) chars.push_back(p.first);

        sort(chars.begin(), chars.end(), [&char_count](char a, char b) {
            return char_count[a] > char_count[b];
        });

        string result;
        for (char c : chars) {
            for (int i = 0; i < char_count[c]; ++i) result += c;
        }

        return result;
    }
};
