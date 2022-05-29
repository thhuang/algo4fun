class Solution {
   public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> got, want;
        for (char c : s) ++got[c];
        for (char c : target) ++want[c];

        int result = numeric_limits<int>::max();
        for (auto [c, i] : want) result = min(result, got[c] / i);

        return result;
    }
};
