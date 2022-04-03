class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> losses;
        unordered_set<int> players;
        for (auto match : matches) {
            players.insert(match[0]);
            players.insert(match[1]);
            ++losses[match[1]];
        }
        
        vector<vector<int>> ans(2);
        for (int p : players) {
            if (losses[p] == 0) ans[0].push_back(p);
            else if (losses[p] == 1) ans[1].push_back(p);
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        
        return ans;
    }
};
