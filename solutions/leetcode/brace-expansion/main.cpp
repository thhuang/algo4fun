class Solution {
   public:
    vector<string> expand(string s) {
        vector<vector<char>> letters;

        int option_start = -1;
        for (int i = 0; i < size(s); ++i) {
            if (s[i] != '{') {
                letters.push_back({s[i]});
                continue;
            }

            vector<char> options;
            while (s[++i] != '}') {
                if (s[i] == ',') continue;
                options.push_back(s[i]);
            }
            sort(begin(options), end(options));
            letters.push_back(options);
        }

        vector<string> ans;
        string curr;
        function<void(int)> search = [&](int i) -> void {
            if (i == size(letters)) {
                ans.push_back(curr);
                return;
            }

            for (char c : letters[i]) {
                curr.push_back(c);
                search(i + 1);
                curr.pop_back();
            }
        };

        search(0);

        return ans;
    }
};
