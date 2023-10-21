class Solution {
   public:
    int shortestDistance(vector<string>& wordsDict, string word1,
                         string word2) {
        int n = wordsDict.size();

        int result = n;

        vector<int> idx1, idx2;
        for (int i = 0; i < n; ++i) {
            if (wordsDict[i] == word1) {
                idx1.push_back(i);
            }
            if (wordsDict[i] == word2) {
                idx2.push_back(i);
            }
        }

        for (int i = 0, j = 0; i < idx1.size() && j < idx2.size();) {
            result = min(result, abs(idx1[i] - idx2[j]));
            idx1[i] < idx2[j] ? ++i : ++j;
        }

        return result;
    }
};
