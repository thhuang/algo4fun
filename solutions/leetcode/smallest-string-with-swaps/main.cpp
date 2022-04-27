class Solution {
    struct UnionFind {
        vector<int> root_;

        UnionFind(int n) : root_(n) { iota(root_.begin(), root_.end(), 0); }

        void unite(int a, int b) {
            int ra = find(a);
            int rb = find(b);
            root_[ra] = rb;
        }

        int find(int a) {
            if (a == root_[a]) return a;
            return root_[a] = find(root_[a]);
        }
    };

   public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();

        UnionFind uf(n);
        for (const auto& p : pairs) uf.unite(p[0], p[1]);

        unordered_map<int, vector<int>> group_idx;
        unordered_map<int, vector<char>> group_char;
        for (int i = 0; i < n; ++i) {
            group_idx[uf.find(i)].push_back(i);
            group_char[uf.find(i)].push_back(s[i]);
        }

        for (auto& p : group_char) sort(p.second.begin(), p.second.end());

        string result = s;
        for (auto pgi : group_idx) {
            int j = 0;
            for (int i : pgi.second) {
                result[i] = group_char[pgi.first][j++];
            }
        }

        return result;
    }
};
