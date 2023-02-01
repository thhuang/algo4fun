class Solution {
    bool isDivisor(string a, string b) {
        if (a.size() > b.size()) return false;
        if (b.size() % a.size() != 0) return false;
        string aa;
        for (int i = 0; i < b.size() / a.size(); ++i) aa += a;
        return b == aa;
    }

   public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.size() > str2.size()) swap(str1, str2);
        string result = "";
        for (int i = 1; i <= str1.size(); ++i) {
            string d = str1.substr(0, i);
            if (isDivisor(d, str1) && isDivisor(d, str2)) {
                result = d;
            }
        }
        return result;
    }
};
