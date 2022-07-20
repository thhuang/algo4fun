class Solution {
   public:
    int numMatchingSubseq(string s, vector<string>& words) {
        array<vector<string_view>, 26> groups;
        for (string& w : words) {
            groups[w.front() - 'a'].push_back(string_view(w));
        }

        int count = 0;
        for (char c : s) {
            auto vec = groups[c - 'a'];
            if (vec.empty()) continue;
            groups[c - 'a'].clear();
            for (string_view w : vec) {
                w.remove_prefix(1);
                if (w.empty()) {
                    ++count;
                    continue;
                }
                groups[w.front() - 'a'].push_back(w);
            }
        }

        return count;
    }
};
