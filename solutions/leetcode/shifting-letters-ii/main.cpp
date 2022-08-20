class Solution {
   public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = 1;
        while (n <= s.size()) n *= 2;
        vector<int> tree(n * 2, 0);

        auto add = [&](int k, int x) -> void {
            k += n;
            tree[k] += x;
            for (k /= 2; k > 0; k /= 2) {
                tree[k] = tree[k * 2] + tree[k * 2 + 1];
            }
        };

        auto sum = [&](int l, int r) -> int {
            l += n;
            r += n;
            int s = 0;
            while (l <= r) {
                if (l % 2 == 1) s += tree[l++];
                if (r % 2 == 0) s += tree[r--];
                l /= 2, r /= 2;
            }
            return s;
        };

        for (const vector<int>& shift : shifts) {
            int d = shift[2] * 2 - 1;
            add(shift[0], d);
            add(shift[1] + 1, -d);
        }

        for (int i = 0; i < s.size(); ++i) {
            int c = s[i] - 'a';
            c = ((c + sum(0, i)) % 26 + 26) % 26;
            s[i] = 'a' + c;
        }

        return s;
    }
};
