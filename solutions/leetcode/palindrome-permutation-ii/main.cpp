class Solution {
   public:
    vector<string> generatePalindromes(string s) {
        array<int, 26> charFreq = {};
        for (char c : s) ++charFreq[c - 'a'];

        string mid = "";
        for (int i = 0; i < 26; ++i) {
            if (charFreq[i] & 1) {
                if (mid != "") return {};
                mid += 'a' + i;
            }
        }

        string t;
        for (int i = 0; i < 26; ++i) {
            int v = charFreq[i];
            if (v < 2) continue;
            t += string(v / 2, 'a' + i);
        }

        vector<string> result;
        unordered_map<string, bool> seen;
        do {
            if (seen[t]) continue;
            seen[t] = true;
            result.push_back(t + mid + string{t.rbegin(), t.rend()});
        } while (next_permutation(t.begin(), t.end()));

        return result;
    }
};
