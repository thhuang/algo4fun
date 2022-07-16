class Solution {
   public:
    int uniqueLetterString(string s) {
        int n = s.size();
        int count = 0;
        for (char c = 'A'; c <= 'Z'; ++c) {
            vector<int> indices = {-1};
            for (int i = 0; i < n; ++i) {
                if (s[i] == c) indices.push_back(i);
            }
            indices.push_back(n);
            for (int i = 1; i < indices.size() - 1; ++i) {
                count += (indices[i] - indices[i - 1]) *
                         (indices[i + 1] - indices[i]);
            }
        }
        return count;
    }
};

class Solution {
   public:
    int uniqueLetterString(string s) {
        int n = s.size();
        int indices[26][2];
        memset(indices, -1, sizeof(indices));

        int count = 0;
        for (int i = 0; i < n; ++i) {
            char c = s[i] - 'A';
            count += (indices[c][1] - indices[c][0]) * (i - indices[c][1]);
            indices[c][0] = indices[c][1];
            indices[c][1] = i;
        }
        for (int c = 0; c < 26; ++c) {
            count += (indices[c][1] - indices[c][0]) * (n - indices[c][1]);
        }

        return count;
    }
};
