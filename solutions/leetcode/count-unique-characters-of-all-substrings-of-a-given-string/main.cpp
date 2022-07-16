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
