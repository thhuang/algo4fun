class Solution {
    string groupShiftHash(const string& s) {
        stringstream ss;
        for (char c : s) {
            ss << ((c - s[0] - 'a') + 26) % 26 << '.';
        }
        return ss.str();
    }

   public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<int>> mp;
        for (int i = 0; i < strings.size(); ++i) {
            mp[groupShiftHash(strings[i])].push_back(i);
        }

        vector<vector<string>> result;
        for (auto [_, idxs] : mp) {
            result.push_back({});
            for (int i : idxs) {
                result.back().push_back(strings[i]);
            }
        }

        return result;
    }
};
