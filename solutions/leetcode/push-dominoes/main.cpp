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

class Solution {
   public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();

        vector<int> right(n, 0);
        for (int i = 0, f = 0; i < n; ++i) {
            if (dominoes[i] == 'R') {
                f = n;
            } else if (dominoes[i] == 'L') {
                f = 0;
            }
            right[i] = f;
            f = max(0, f - 1);
        }

        vector<int> left(n, 0);
        for (int i = n - 1, f = 0; i >= 0; --i) {
            if (dominoes[i] == 'L') {
                f = -n;
            } else if (dominoes[i] == 'R') {
                f = 0;
            }
            left[i] = f;
            f = min(0, f + 1);
        }

        string result;
        for (int i = 0; i < n; ++i) {
            int f = right[i] + left[i];
            if (f < 0) {
                result += 'L';
            } else if (f > 0) {
                result += 'R';
            } else {
                result += '.';
            }
        }

        return result;
    }
};
