class Solution {
   public:
    string rankTeams(vector<string>& votes) {
        array<array<int, 26>, 26> teams;
        for (auto& t : teams) t.fill(0);

        for (const string& s : votes) {
            for (int i = 0; i < s.size(); ++i) ++teams[s[i] - 'A'][i];
        }

        string result = votes.front();
        sort(result.begin(), result.end(),
             [&](const char& a, const char& b) -> bool {
                 for (int i = 0; i < result.size(); ++i) {
                     if (teams[a - 'A'][i] != teams[b - 'A'][i])
                         return teams[a - 'A'][i] > teams[b - 'A'][i];
                 }
                 return a < b;
             });

        return result;
    }
};
