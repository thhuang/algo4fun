class Solution {
   public:
    int compress(vector<char>& chars) {
        int p = 0;
        for (int l = 0, n = chars.size(); l < n;) {
            int r = l + 1;
            while (r < n && chars[r] == chars[l]) ++r;

            if (r - l == 1) {
                chars[p++] = chars[l++];
                continue;
            }

            chars[p++] = chars[l];
            for (auto c : to_string(r - l)) chars[p++] = c;
            l = r;
        }
        return p;
    }
};

class Solution {
   public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int p = 0;
        for (int l = 0; l < n;) {
            int r = l + 1;
            while (r < n && chars[l] == chars[r]) ++r;

            int d = r - l;
            chars[p++] = chars[l];
            l = r;

            if (d == 1) continue;
            for (char c : to_string(d)) chars[p++] = c;
        }
        return p;
    }
};
