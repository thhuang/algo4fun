class Solution {
   public:
    int countCharacters(vector<string>& words, string chars) {
        array<int, 26> target = {};
        for (char c : chars) ++target[c - 'a'];

        int result = 0;

        for (const string& w : words) {
            auto t = target;
            bool good = true;
            for (char c : w) good = good && --t[c - 'a'] >= 0;
            if (good) result += w.size();
        }

        return result;
    }
};
