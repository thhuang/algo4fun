class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        string s;
        int open = n, close = n;
        function<void()> search = [&]() -> void {
            if (open == 0 && close == 0) {
                result.push_back(s);
                return;
            }
            if (open > 0) {
                s.push_back('('), --open;
                search();
                s.pop_back(), ++open;
            }
            if (close > open) {
                s.push_back(')'), --close;
                search();
                s.pop_back(), ++close;
            }
        };

        search();

        return result;
    }
};

class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        int open = 0;
        string curr;

        function<void(int)> dfs = [&](int i) -> void {
            if (i == n * 2) {
                result.push_back(curr);
                return;
            }

            if (curr.size() + open + 2 <= n * 2) {
                curr.push_back('('), ++open;
                dfs(i + 1);
                curr.pop_back(), --open;
            }

            if (open > 0) {
                curr.push_back(')'), --open;
                dfs(i + 1);
                curr.pop_back(), ++open;
            }
        };

        dfs(0);

        return result;
    }
};

class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        string s;
        int open = 0;
        function<void(int)> dfs = [&](int i) -> void {
            if (i == n * 2 - 1) {
                if (open == 1) result.push_back(s + ')');
                return;
            }

            ++open;
            s.push_back('(');
            dfs(i + 1);
            s.pop_back();
            --open;

            if (open == 0) return;

            --open;
            s.push_back(')');
            dfs(i + 1);
            s.pop_back();
            ++open;
        };

        dfs(0);

        return result;
    }
};

class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        string curr;
        int open = n, close = n;
        function<void(int)> search = [&](int i) -> void {
            if (i == n * 2) {
                result.push_back(curr);
                return;
            }

            if (open > 0) {
                --open;
                curr.push_back('(');
                search(i + 1);
                curr.pop_back();
                ++open;
            }

            if (close > open) {
                --close;
                curr.push_back(')');
                search(i + 1);
                curr.pop_back();
                ++close;
            }
        };

        search(0);

        return result;
    }
};
