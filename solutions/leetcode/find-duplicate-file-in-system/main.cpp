class Solution {
   public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mp;
        for (const string& s : paths) {
            string_view sv(s);

            auto dir = sv.substr(0, sv.find(' '));
            sv.remove_prefix(dir.size() + 1);

            while (!sv.empty()) {
                auto file = sv.substr(0, sv.find(' '));
                sv.remove_prefix(min(sv.size(), file.size() + 1));

                auto name = file.substr(0, file.find('('));
                file.remove_prefix(name.size() + 1);
                file.remove_suffix(1);
                mp[string(file)].push_back(string(dir) + "/" + string(name));
            }
        }

        vector<vector<string>> result;
        for (auto [_, ps] : mp) {
            if (ps.size() > 1) result.push_back(ps);
        }

        return result;
    }
};
