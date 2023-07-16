class Solution {
   public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills,
                                       vector<vector<string>>& people) {
        int m = req_skills.size();
        int n = people.size();

        unordered_map<string, int> skillToIndex;
        for (int i = 0; i < m; ++i) skillToIndex[req_skills[i]] = i;

        vector<int> peopleSkills(n, 0);
        for (int i = 0; i < n; ++i) {
            for (string& s : people[i]) {
                peopleSkills[i] |= 1 << skillToIndex[s];
            }
        }

        vector<long long> dp(1 << m, -1);
        function<long long(int)> dfs = [&](int skillsMask) -> long long {
            if (skillsMask == 0) return 0;
            if (dp[skillsMask] != -1) return dp[skillsMask];

            long long result = (1LL << n) - 1;

            for (int i = 0; i < n; ++i) {
                int newSkillsMask = skillsMask & ~peopleSkills[i];
                if (newSkillsMask == skillsMask) continue;

                long long peopleMask = dfs(newSkillsMask) | (1LL << i);
                if (result == -1 || __builtin_popcountll(peopleMask) < __builtin_popcountll(result)) {
                    result = peopleMask;
                }
            }

            return dp[skillsMask] = result;
        };

        long long bresult = dfs((1 << m) - 1);
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if ((bresult >> i) & 1) result.push_back(i);
        }

        return result;
    }
};
