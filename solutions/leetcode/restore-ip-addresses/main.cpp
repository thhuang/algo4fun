class Solution {
   public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;

        vector<string> curr;
        string v;
        function<void(int)> dfs = [&](int i) -> void {
            if (i == s.size()) {
                if (curr.size() == 4) {
                    string ip = curr.front();
                    for (int j = 1; j < 4; ++j) ip += '.' + curr[j];
                    result.push_back(ip);
                }
                return;
            }
            if (curr.size() == 4) return;

            v += s[i];

            if (stoi(v) < 256) {
                if (v != "0") dfs(i + 1);

                curr.push_back(v);
                v.clear();

                dfs(i + 1);

                v = curr.back();
                curr.pop_back();
            }

            v.pop_back();
        };

        dfs(0);

        return result;
    }
};
