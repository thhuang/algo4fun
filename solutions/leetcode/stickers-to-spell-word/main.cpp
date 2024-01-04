class Solution {
    const int inf = 1e9;

   public:
    int minStickers(vector<string>& stickers, string target) {
        vector<unordered_map<char, int>> stickerFreqs;
        for (string& s : stickers) {
            unordered_map<char, int> freq;
            for (char c : s) {
                ++freq[c];
            }
            stickerFreqs.push_back(freq);
        }

        unordered_map<string, int> cache;
        function<int(string)> dfs = [&](string t) -> int {
            if (cache.count(t)) {
                return cache[t];
            }

            if (t.empty()) {
                return 0;
            }

            unordered_map<char, int> tFreq;
            for (char c : t) {
                ++tFreq[c];
            }

            int result = inf;

            for (auto& stickerFreq : stickerFreqs) {
                unordered_map<char, int> tFreqNew = tFreq;

                if (stickerFreq.count(*t.begin()) == 0) {
                    continue;
                }

                for (auto [c, v] : stickerFreq) {
                    tFreqNew[c] = max(0, tFreq[c] - v);
                }

                string tNew;
                for (auto [c, v] : tFreqNew) {
                    while (v-- > 0) {
                        tNew.push_back(c);
                    }
                }

                result = min(result, 1 + dfs(tNew));
            }

            return cache[t] = result;
        };

        sort(target.begin(), target.end());
        int result = dfs(target);

        return result < inf ? result : -1;
    }
};
