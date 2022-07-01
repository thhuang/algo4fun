class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const string& s : strs) {
            unordered_map<char, int> count;
            for (char c : s) ++count[c];

            stringstream ss;
            for (int i = 0; i < 26; ++i) {
                char c = 'a' + i;
                ss << c << count[c];
            }

            groups[ss.str()].push_back(s);
        }

        vector<vector<string>> result;
        for (auto it = groups.begin(); it != groups.end(); ++it)
            result.emplace_back(move(it->second));

        return result;
    }
};

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (const string& s : strs) {
            string k = s;
            sort(k.begin(), k.end());
            groups[k].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto& [_, vec] : groups) result.push_back(vec);
        return result;
    }
};
