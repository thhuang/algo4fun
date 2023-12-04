class Solution {
   public:
    string largestGoodInteger(string num) {
        string s;
        string w = num.substr(0, 2);
        for (int i = 2; i < num.size(); ++i) {
            w += num[i];
            if (w[0] == w[1] && w[1] == w[2]) {
                s = max(s, w);
            }
            w = w.substr(1, 2);
        }
        return s;
    }
};

class Solution {
   public:
    string largestGoodInteger(string num) {
        string result = "";
        for (int l = 0; l < num.size() - 2; ++l) {
            if (num[l] == num[l + 1] && num[l] == num[l + 2] &&
                (result == "" || num[l] > result[0])) {
                result = num.substr(l, 3);
            }
        }
        return result;
    }
};
