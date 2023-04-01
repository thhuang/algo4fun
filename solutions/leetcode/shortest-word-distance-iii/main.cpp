class Solution {
   public:
    int shortestWordDistance(vector<string> &wordsDict, string word1,
                             string word2) {
        int n = wordsDict.size();

        unordered_map<string, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            mp[wordsDict[i]].push_back(i);
        }

        int result = numeric_limits<int>::max();

        if (word1 == word2) {
            vector<int> &indices = mp[word1];
            for (int i = 0; i < indices.size() - 1; ++i) {
                result = min(result, indices[i + 1] - indices[i]);
            }
        } else {
            vector<int> &indices1 = mp[word1];
            vector<int> &indices2 = mp[word2];
            while (!indices1.empty() && !indices2.empty()) {
                int i = indices1.back();
                int j = indices2.back();
                if (i < j) {
                    result = min(result, j - i);
                    indices2.pop_back();
                } else {
                    result = min(result, i - j);
                    indices1.pop_back();
                }
            }
        }

        return result;
    }
};
