class Solution {
   public:
    int maxLength(vector<string>& arr) {
        int result = 0;
        int cnt = 0;
        array<bool, 26> vis;
        vis.fill(0);

        function<void(int)> dfs = [&](int i) -> void {
            if (i == arr.size()) {
                result = max(result, cnt);
                return;
            }

            dfs(i + 1);

            for (char c : arr[i]) {
                if (vis[c - 'a']) return;
            }

            sort(arr[i].begin(), arr[i].end());
            if (unique(arr[i].begin(), arr[i].end()) - arr[i].begin() < arr[i].size()) return;

            for (char c : arr[i]) ++cnt, vis[c - 'a'] = true;
            dfs(i + 1);
            for (char c : arr[i]) --cnt, vis[c - 'a'] = false;
        };

        dfs(0);

        return result;
    }
};
