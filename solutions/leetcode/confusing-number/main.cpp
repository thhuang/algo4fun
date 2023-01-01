class Solution {
    const unordered_map<char, char> mp = {
        {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};

   public:
    bool confusingNumber(int n) {
        string s = to_string(n);
        string t;
        for (char c : s) {
            auto it = mp.find(c);
            if (it == mp.end()) return false;
            t += it->second;
        }
        reverse(t.begin(), t.end());
        return s != t;
    }
};
