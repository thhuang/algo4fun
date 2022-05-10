class Solution {
   public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int final_shift = 0;
        for (const auto& s : shift) {
            final_shift += s[1] * (s[0] == 1 ? 1 : -1);
        }

        int n = s.size();
        final_shift = final_shift % n;
        if (final_shift < 0) final_shift += n;

        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + final_shift);
        reverse(s.begin() + final_shift, s.end());

        return s;
    }
};
