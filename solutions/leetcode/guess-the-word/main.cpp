/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
   public:
    void findSecretWord(vector<string>& words, Master& master) {
        int n = words.size();

        vector<vector<vector<int>>> wordSameList(n, vector<vector<int>>(6));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                int v = 0;
                for (int k = 0; k < 6; ++k) {
                    if (words[i][k] == words[j][k]) ++v;
                }
                wordSameList[i][v].push_back(j);
            }
        }

        vector<bool> vis(n, false);
        unordered_set<int> candidates(n);
        for (int i = n - 1; i >= 0; --i) candidates.insert(i);

        while (!candidates.empty()) {
            int i = *candidates.begin();
            candidates.erase(i);

            if (vis[i]) continue;
            vis[i] = true;

            int v = master.guess(words[i]);
            if (v == 6) return;

            unordered_set<int> candidatesNew;

            for (int j : wordSameList[i][v]) {
                if (candidates.count(j) > 0) {
                    candidatesNew.insert(j);
                }
            }

            candidates = candidatesNew;
        }
    }
};
