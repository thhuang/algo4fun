class Solution {
   public:
    int compress(vector<char>& chars) {
        int p = 0;
        for (int l = 0; l < chars.size();) {
            int r = l;
            while (r < chars.size() && chars[r] == chars[l]) ++r;

            chars[p++] = chars[l];

            int v = r - l;
            if (v > 1)
                for (char c : to_string(v)) chars[p++] = c;

            l = r;
        }
        return p;
    }
};
