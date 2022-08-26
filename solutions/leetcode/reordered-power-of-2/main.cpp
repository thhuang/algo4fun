array<vector<array<int, 10>>, 11> mp;
bool init = false;

class Solution {
   public:
    bool reorderedPowerOf2(int n) {
        if (!init) {
            for (int v = 1; v <= 1e9; v *= 2) {
                string s = to_string(v);

                array<int, 10> cnt;
                cnt.fill(0);

                for (char c : s) ++cnt[c - '0'];

                mp[s.size()].push_back(cnt);
            }
            init = true;
        }

        string s = to_string(n);

        array<int, 10> cnt;
        cnt.fill(0);

        for (char c : s) ++cnt[c - '0'];

        for (const auto& arr : mp[s.size()]) {
            int found = true;
            for (int i = 0; found && i < 10; ++i) {
                if (arr[i] != cnt[i]) {
                    found = false;
                }
            }
            if (found) return true;
        }

        return false;
    }
};
