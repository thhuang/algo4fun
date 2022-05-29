class Solution {
   public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<pair<bitset<26>, int>> hash_length(n, {0, 0});

        for (int i = 0; i < n; ++i) {
            for (char c : words[i]) {
                hash_length[i].first[c - 'a'] = 1;
            }
            hash_length[i].second = words[i].size();
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((hash_length[i].first & hash_length[j].first).count())
                    continue;
                result =
                    max(result, hash_length[i].second * hash_length[j].second);
            }
        }

        return result;
    }
};
