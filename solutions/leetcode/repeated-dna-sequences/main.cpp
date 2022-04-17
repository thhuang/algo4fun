class Solution {
   public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) return {};

        string curr = s.substr(0, 10);
        unordered_map<string, int> count;
        ++count[curr];

        for (int i = 10; i < s.size(); ++i) {
            curr = curr.substr(1) + s[i];
            ++count[curr];
        }

        vector<string> result;
        for (auto it = count.begin(); it != count.end(); ++it) {
            if (it->second > 1) result.push_back(it->first);
        }

        return result;
    }
};
