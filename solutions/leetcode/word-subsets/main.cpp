class Solution {
   public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        size_t sz = 0;
        array<int, 26> count;
        fill(count.begin(), count.end(), 0);
        for (const string& w : words2) {
            sz = max(sz, w.size());

            array<int, 26> cnt;
            fill(cnt.begin(), cnt.end(), 0);
            for (const char& c : w) ++cnt[c - 'a'];

            for (int i = 0; i < 26; ++i) count[i] = max(count[i], cnt[i]);
        }

        vector<string> result;
        for (const string& w : words1) {
            if (w.size() < sz) continue;

            array<int, 26> cnt;
            fill(cnt.begin(), cnt.end(), 0);
            for (const char& c : w) ++cnt[c - 'a'];

            bool valid = true;
            for (int i = 0; i < 26; ++i) {
                if (count[i] > cnt[i]) {
                    valid = false;
                    break;
                }
            }

            if (valid) result.push_back(w);
        }

        return result;
    }
};
