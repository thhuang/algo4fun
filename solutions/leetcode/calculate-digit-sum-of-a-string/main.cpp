class Solution {
   public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            int n = s.size();
            string new_s;
            for (int l = 0; l < s.size(); l += k) {
                int r = min(l + k, int(s.size()));
                int v = 0;
                for (char c : s.substr(l, r - l)) v += c - '0';
                new_s += to_string(v);
            }
            s = new_s;
        }
        return s;
    }
};

class Solution {
   public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string new_s;
            for (int i = 0; i < s.size(); i += k) {
                int v = 0;
                for (char c : s.substr(i, min(k, (int)s.size() - i))) {
                    v += c - '0';
                }
                new_s += to_string(v);
            }
            s = move(new_s);
        }
        return s;
    }
};
