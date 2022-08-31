class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (const string& s : strs) {
            array<int, 26> cnt;
            cnt.fill(0);
            for (char c : s) ++cnt[c - 'a'];

            string k;
            for (int v : cnt) k += to_string(v) + ':';
            mp[k].push_back(s);
        }

        vector<vector<string>> result;
        for (auto [k, v] : mp) result.push_back(v);

        return result;
    }
};

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (const string& s : strs) {
            string k = s;
            sort(k.begin(), k.end());
            mp[k].push_back(s);
        }

        vector<vector<string>> result;
        for (auto [_, v] : mp) result.push_back(v);

        return result;
    }
};
