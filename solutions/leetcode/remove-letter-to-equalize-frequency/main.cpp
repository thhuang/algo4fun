class Solution {
   public:
    bool equalFrequency(string word) {
        unordered_map<char, int> char2count;
        for (char c : word) ++char2count[c];

        if (char2count.size() == 1) return true;

        map<int, int> mp;
        for (auto [_, v] : char2count) ++mp[v];

        if (mp.size() == 1 && mp.begin()->first == 1) return true;
        if (mp.size() != 2) return false;
        if (auto [cnt, char_cnt] = *mp.begin(); char_cnt == 1 && cnt == 1) return true;
        if (auto [cnt, char_cnt] = *mp.rbegin(); char_cnt == 1 && cnt == mp.begin()->first + 1) return true;
        return false;
    }
};
