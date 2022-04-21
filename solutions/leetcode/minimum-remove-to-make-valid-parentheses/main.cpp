class Solution {
   public:
    string minRemoveToMakeValid(string s) {
        vector<int> opens;
        unordered_set<int> skips;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                opens.push_back(i);
            } else if (s[i] == ')') {
                if (opens.empty()) {
                    skips.insert(i);
                } else {
                    opens.pop_back();
                }
            }
        }

        for (int v : opens) skips.insert(v);

        string result;
        for (int i = 0; i < s.size(); ++i) {
            if (skips.count(i)) continue;
            result += s[i];
        }

        return result;
    }
};
