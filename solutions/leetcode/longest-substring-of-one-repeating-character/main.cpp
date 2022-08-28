class Solution {
    struct Node {
        int longest = 0;
        char l = ' ';
        char r = ' ';
        int lsz = 0;
        int rsz = 0;
    };

   public:
    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {
        int n = 1;
        while (n <= s.size()) n *= 2;

        vector<Node> tree(n * 2);

        auto update = [&](int k, char c) -> int {
            k += n;
            tree[k] = {1, c, c, 1, 1};

            k /= 2;
            for (int sz = 1; k > 0; k /= 2, sz *= 2) {
                const auto& left = tree[k * 2];
                const auto& right = tree[k * 2 + 1];
                tree[k] = {max(left.longest, right.longest), left.l, right.r,
                           left.lsz, right.rsz};

                if (left.r != right.l) continue;
                int msz = left.rsz + right.lsz;
                tree[k].longest = max(tree[k].longest, msz);

                if (left.lsz == sz) tree[k].lsz = msz;
                if (right.rsz == sz) tree[k].rsz = msz;
            }
            return tree[1].longest;
        };

        for (int i = 0; i < s.size(); ++i) update(i, s[i]);

        vector<int> result(queryCharacters.size());
        for (int i = 0; i < queryCharacters.size(); ++i) {
            result[i] = update(queryIndices[i], queryCharacters[i]);
        }

        return result;
    }
};
