unordered_set<string> valid;

class Solution {
   public:
    bool reorderedPowerOf2(int n) {
        if (valid.empty()) {
            for (int v = 1; v <= 1e9; v *= 2) {
                string s = to_string(v);
                sort(s.begin(), s.end());
                valid.insert(s);
            }
        }

        string s = to_string(n);
        sort(s.begin(), s.end());
        return valid.find(s) != valid.end();
    }
};
