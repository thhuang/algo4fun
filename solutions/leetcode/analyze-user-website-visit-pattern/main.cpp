class Solution {
   public:
    vector<string> mostVisitedPattern(vector<string>& username,
                                      vector<int>& timestamp,
                                      vector<string>& website) {
        int n = username.size();

        unordered_map<string, int> website_ids;
        unordered_map<string, vector<tuple<int, string>>> user_pattern;

        for (int i = 0, wid = 0; i < n; ++i) {
            user_pattern[username[i]].push_back({timestamp[i], website[i]});
            if (website_ids.count(website[i]) == 0)
                website_ids[website[i]] = wid++;
        }

        int w = website_ids.size();
        vector<string> websites(w);
        for (const auto p : website_ids) websites[p.second] = p.first;

        for (auto& kv : user_pattern) sort(kv.second.begin(), kv.second.end());

        int max_count = 0;
        vector<vector<vector<int>>> pattern_count(
            w, vector<vector<int>>(w, vector<int>(w, 0)));
        for (auto it = user_pattern.begin(); it != user_pattern.end(); ++it) {
            vector<vector<vector<bool>>> vis(
                w, vector<vector<bool>>(w, vector<bool>(w, false)));
            int m = it->second.size();
            for (int i = 0; i < m; ++i) {
                for (int j = i + 1; j < m; ++j) {
                    for (int k = j + 1; k < m; ++k) {
                        int a = website_ids[get<1>(it->second[i])];
                        int b = website_ids[get<1>(it->second[j])];
                        int c = website_ids[get<1>(it->second[k])];
                        if (vis[a][b][c]) continue;
                        vis[a][b][c] = true;
                        max_count = max(max_count, ++pattern_count[a][b][c]);
                    }
                }
            }
        }

        vector<string> result;
        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < w; ++j) {
                for (int k = 0; k < w; ++k) {
                    if (pattern_count[i][j][k] < max_count) continue;
                    if (result.empty()) {
                        result = {websites[i], websites[j], websites[k]};
                        continue;
                    }
                    if (websites[i] > result[0]) continue;
                    if (websites[i] < result[0]) {
                        result = {websites[i], websites[j], websites[k]};
                        continue;
                    }
                    if (websites[j] > result[1]) continue;
                    if (websites[j] < result[1]) {
                        result = {websites[i], websites[j], websites[k]};
                        continue;
                    }
                    if (websites[k] > result[2]) continue;
                    if (websites[k] < result[2]) {
                        result = {websites[i], websites[j], websites[k]};
                        continue;
                    }
                }
            }
        }

        return result;
    }
};

class Solution {
   public:
    vector<string> mostVisitedPattern(vector<string>& username,
                                      vector<int>& timestamp,
                                      vector<string>& website) {
        unordered_map<string, vector<pair<int, string>>> user_visits;
        for (int i = 0; i < username.size(); ++i) {
            user_visits[username[i]].push_back({timestamp[i], website[i]});
        }

        unordered_map<string, int> patterns;
        for (auto& [user, visits] : user_visits) {
            if (visits.size() < 3) continue;
            sort(visits.begin(), visits.end());

            unordered_set<string> seen;
            for (int i = 0; i < visits.size(); ++i) {
                for (int j = i + 1; j < visits.size(); ++j) {
                    for (int k = j + 1; k < visits.size(); ++k) {
                        string p = visits[i].second + ":" + visits[j].second +
                                   ":" + visits[k].second;
                        if (seen.count(p)) continue;
                        seen.insert(p);
                        ++patterns[p];
                    }
                }
            }
        }

        string mvp;
        int v = 0;
        for (const auto& [p, c] : patterns) {
            if ((c == v && p < mvp) || c > v) v = c, mvp = p;
        }

        auto i = find(mvp.begin(), mvp.end(), ':') - mvp.begin();
        auto j = find(mvp.begin() + i + 1, mvp.end(), ':') - mvp.begin();
        return {mvp.substr(0, i), mvp.substr(i + 1, j - i - 1),
                mvp.substr(j + 1)};
    }
};
