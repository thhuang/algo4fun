class Solution {
   public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        array<int, 26> eq;
        for (char c = 'a'; c <= 'z'; ++c) eq[c - 'a'] = c - 'a';

        function<int(int)> find = [&](int v) -> int {
            if (eq[v] == v) return v;
            return eq[v] = find(eq[v]);
        };

        auto unite = [&](int a, int b) -> void {
            int p = find(eq[a]);
            int q = find(eq[b]);
            if (p < q) {
                eq[q] = p;
            } else {
                eq[p] = q;
            }
        };

        for (int i = 0; i < s1.size(); ++i) {
            unite(s1[i] - 'a', s2[i] - 'a');
        }

        string result;
        for (char c : baseStr) result += 'a' + find(c - 'a');

        return result;
    }
};
