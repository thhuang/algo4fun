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
