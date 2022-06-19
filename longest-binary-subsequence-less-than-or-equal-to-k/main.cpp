class Solution {
   public:
    int longestSubsequence(string s, int k) {
        int result = 0;
        vector<int> ones;
        for (int i = 0; i < s.size(); ++i) {
            if (s[s.size() - 1 - i] == '0') {
                ++result;
            } else {
                ones.push_back(i);
            }
        }

        long long v = 0;
        for (int i = 0; i < ones.size(); ++i) {
            if (ones[i] > 31) break;
            v += (1LL << ones[i]);
            if (v > k) break;
            ++result;
        }

        return result;
    }
};
