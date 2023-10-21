class WordDistance {
    unordered_map<string, vector<int>> wordIdxs;

   public:
    WordDistance(vector<string>& wordsDict) {
        for (int i = 0; i < wordsDict.size(); ++i) {
            wordIdxs[wordsDict[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int result = numeric_limits<int>::max();

        const auto idx1 = wordIdxs[word1];
        const auto idx2 = wordIdxs[word2];

        for (int i = 0, j = 0; i < idx1.size() && j < idx2.size();
             idx1[i] < idx2[j] ? ++i : ++j) {
            result = min(result, abs(idx1[i] - idx2[j]));
        }

        return result;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
