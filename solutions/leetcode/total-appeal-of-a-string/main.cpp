class Solution {
   public:
    long long appealSum(string s) {
        int n = s.size();

        long long count = 0;
        unordered_map<char, deque<int>> chars;
        for (int i = 0; i < n; ++i) {
            chars[s[i]].push_back(i);
            count += chars.size();
        }
        for (auto& p : chars) p.second.push_back(n);

        long long result = count;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            count -= chars[c][1] - chars[c][0];
            chars[c].pop_front();
            result += count;
        }

        return result;
    }
};

class Solution {
   public:
    long long appealSum(string s) {
        int n = s.size();
        array<vector<int>, 26> char_indices;

        for (int i = 0; i < n; ++i) {
            char_indices[s[i] - 'a'].push_back(i);
        }

        long long result = 0;
        for (int i = 0; i < 26; ++i) {
            char_indices[i].push_back(n);
            for (int j = 0; j < char_indices[i].size() - 1; ++j) {
                result += (1LL + char_indices[i][j]) *
                          (char_indices[i][j + 1] - char_indices[i][j]);
            }
        }

        return result;
    }
};
