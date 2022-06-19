class Solution {
   public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + sentence[i].size() + 1;

        int k = cols + 1;
        int count = 0;
        int offset = 1;
        while (rows) {
            auto it = upper_bound(prefix.begin() + offset, prefix.end(), k,
                                  [&](int t, int v) -> bool {
                                      return t < v - prefix[offset - 1];
                                  });
            if (it != prefix.end()) {
                offset = it - prefix.begin();
                --rows;
                k = cols + 1;
                continue;
            }

            ++count;
            k -= prefix.back() - prefix[offset - 1];
            if (int v = k / prefix.back(); v > 0) {
                k -= prefix.back() * v;
                count += v;
            }
            offset = 1;
        }

        return count;
    }
};

class Solution {
   public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size();
        vector<int> cache(n, -1);
        int count = 0;
        for (int i = 0; i < rows; ++i) {
            int start = count % n;
            if (cache[start] != -1) {
                count += cache[start];
                continue;
            }

            int k = cols;
            int v = 0;
            for (int j = start; k >= (int)sentence[j].size(); j = (j + 1) % n) {
                k -= sentence[j].size() + 1;
                ++v;
            }
            count += cache[start] = v;
        }
        return count / n;
    }
};
