class Solution {
   public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<pair<int, char>> force;
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] == '.') continue;
            force.push_back({i, dominoes[i]});
        }

        string result(n, '.');
        while (!force.empty()) {
            vector<pair<int, char>> new_force;
            vector<bool> right(n, false), left(n, false);
            for (auto [i, f] : force) {
                if (i < 0 || i >= n) continue;
                f == 'R' ? right[i] = true : left[i] = true;
            }
            for (auto [i, _] : force) {
                if (i < 0 || i >= n) continue;
                if (result[i] == 'R' || result[i] == 'L') continue;
                if (right[i] && left[i]) {
                    result[i] = '.';
                } else if (right[i]) {
                    result[i] = 'R';
                    new_force.push_back({i + 1, 'R'});
                } else if (left[i]) {
                    result[i] = 'L';
                    new_force.push_back({i - 1, 'L'});
                }
            }
            force = move(new_force);
        }

        return result;
    }
};
