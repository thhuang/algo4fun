class Solution {
   public:
    int minimumTeachings(int n, vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {
        vector<unordered_set<int>> langRequired(n);

        for (auto& f : friendships) {
            int u = f[0] - 1;
            int v = f[1] - 1;
            set<int> ulang(languages[u].begin(), languages[u].end());
            set<int> vlang(languages[v].begin(), languages[v].end());

            bool intersect = false;
            for (int l : vlang) {
                if (ulang.count(l) > 0) {
                    intersect = true;
                    break;
                }
            }
            if (intersect) {
                continue;
            }

            for (int l = 1; l <= n; ++l) {
                if (ulang.count(l) == 0) {
                    langRequired[l - 1].insert(u);
                }
                if (vlang.count(l) == 0) {
                    langRequired[l - 1].insert(v);
                }
            }
        }

        int result = languages.size();
        for (const auto& users : langRequired) {
            result = min(result, (int)users.size());
        }

        return result;
    }
};
