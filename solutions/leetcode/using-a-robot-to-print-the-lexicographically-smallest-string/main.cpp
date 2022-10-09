class Solution {
   public:
    string robotWithString(string s) {
        int n = s.size();

        multiset<int> chars;
        for (char c : s) chars.insert(-int(c));

        reverse(s.begin(), s.end());

        string result, t;
        while (!s.empty()) {
            while (t.empty() ||
                   chars.upper_bound(-int(t.back())) != chars.end()) {
                char c = s.back();
                t += c;
                s.pop_back();
                chars.erase(chars.find(-int(c)));
            }
            result += t.back();
            t.pop_back();
        }

        reverse(t.begin(), t.end());

        return result + t;
    }
};
