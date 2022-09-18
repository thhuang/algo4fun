class Solution {
    string order = "abcdefghijklmnopqrstuvwxyz";

   public:
    int longestContinuousSubstring(string s) {
        int result = 0;
        for (int l = 0; l < s.size();) {
            int i = lower_bound(order.begin(), order.end(), s[l]) - order.begin();
            int r = l;
            while (r < s.size() && i < 26 && order[i] == s[r]) ++i, ++r;
            result = max(result, r - l);
            l = r;
        }
        return result;
    }
};
