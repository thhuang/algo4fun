class Solution {
   public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<char, unordered_set<string>> mp;
        for (const auto& s : ideas) mp[s[0]].insert(s.substr(1));

        long long result = 0;
        for (const auto& [a, seta] : mp) {
            for (const auto& [b, setb] : mp) {
                if (a >= b) continue;
                int same = 0;
                for (const string& s : seta) {
                    if (setb.count(s)) ++same;
                }
                result += (seta.size() - same) * (setb.size() - same);
            }
        }

        return result * 2;
    }
};
