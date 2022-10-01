class Solution {
   public:
    bool equalFrequency(string word) {
        unordered_map<char, int> cnt;
        for (char c : word) ++cnt[c];
        if (cnt.size() == 1) return true;

        map<int, int> vals;
        for (auto [_, v] : cnt) ++vals[v];

        if (vals.size() == 1 && vals.begin()->first == 1) return true;
        if (vals.size() != 2) return false;

        if (abs(vals.begin()->first - vals.rbegin()->first) == 1 &&
            (vals.begin()->second == 1 || vals.rbegin()->second == 1))
            return true;

        return false;
    }
};
