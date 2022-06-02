class Solution {
    struct Node {
        Node() : children(array<Node*, 26>()) {}

        bool is_end = false;
        array<Node*, 26> children;
    };

    void insert(const string& s) {
        auto p = root;
        for (char c : s) {
            int i = c - 'a';
            if (!p->children[i]) p->children[i] = new Node;
            p = p->children[i];
        }
        p->is_end = true;
    }

    const vector<array<int, 2>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    Node* root = new Node;

   public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        for (const auto& s : words) insert(s);

        int m = board.size();
        int n = board.front().size();

        int count = words.size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<string> result;
        string s;
        function<void(int, int, Node* p)> dfs = [&](int i, int j,
                                                    Node* p) -> void {
            if (p == nullptr) return;
            if (vis[i][j]) return;
            vis[i][j] = true;
            s.push_back(board[i][j]);

            if (p->is_end) {
                result.push_back(s);
                p->is_end = false;
                --count;
            }

            for (auto [di, dj] : directions) {
                int ii = i + di, jj = j + dj;
                if (ii < 0 || ii >= m || jj < 0 || jj >= n) continue;
                int k = board[ii][jj] - 'a';
                dfs(ii, jj, p->children[k]);
            }

            s.pop_back();
            vis[i][j] = false;
        };

        for (int i = 0; i < m && count; ++i) {
            for (int j = 0; j < n && count; ++j) {
                int k = board[i][j] - 'a';
                dfs(i, j, root->children[k]);
            }
        }

        return result;
    }
};
