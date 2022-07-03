class Solution {
    const vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    struct Node {
        array<Node*, 26> children = array<Node*, 26>();
        const string* s = nullptr;
    };

    Node* root = new Node;

    void insert(const string& s) {
        auto p = root;
        for (char c : s) {
            int i = c - 'a';
            if (p->children[i] == nullptr) p->children[i] = new Node;
            p = p->children[i];
        }
        p->s = &s;
    }

   public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        for (const string& s : words) insert(s);

        int m = board.size();
        int n = board.front().size();
        int count = words.size();

        vector<string> result;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        function<void(int, int, Node*)> dfs = [&](int i, int j,
                                                  Node* p) -> void {
            if (p == nullptr) return;
            if (vis[i][j]) return;
            vis[i][j] = true;

            if (p->s) {
                result.push_back(*p->s);
                p->s = nullptr;
                --count;
            }

            for (const auto [di, dj] : directions) {
                int ii = i + di, jj = j + dj;
                if (ii < 0 || ii >= m || jj < 0 || jj >= n) continue;
                dfs(ii, jj, p->children[board[ii][jj] - 'a']);
            }

            vis[i][j] = false;
        };

        for (int i = 0; i < m && count; ++i) {
            for (int j = 0; j < n && count; ++j) {
                dfs(i, j, root->children[board[i][j] - 'a']);
            }
        }

        return result;
    }
};
