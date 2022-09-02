class Solution {
   public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> groups;
        unordered_map<string, string> group2name;

        function<string(string)> find = [&](string k) -> string {
            if (groups[k] == k) return k;
            return groups[k] = find(groups[k]);
        };

        function<void(string, string)> unite = [&](string a, string b) -> void {
            string pa = find(a);
            string pb = find(b);
            if (pa == pb) return;
            groups[pb] = pa;
        };

        for (const vector<string>& vec : accounts) {
            const string& name = vec[0];

            const string& g = vec[1];
            for (int i = 1; i < vec.size(); ++i) {
                if (!groups.count(vec[i])) {
                    groups[vec[i]] = g;
                    group2name[g] = name;
                }
                if (i > 1) unite(vec[i - 1], vec[i]);
            }
        }

        unordered_map<string, vector<string>> group2emails;
        for (const auto& [email, _] : groups)
            group2emails[find(email)].push_back(email);

        vector<vector<string>> result;
        for (auto& [group, emails] : group2emails) {
            sort(emails.begin(), emails.end());
            result.push_back({group2name[group]});
            for (int i = 0; i < emails.size(); ++i)
                result.back().push_back(emails[i]);
        }

        return result;
    }
};
