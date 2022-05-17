class Solution {
   public:
    string decodeString(string s) {
        vector<int> nums;
        vector<string> strs;
        int v = 0;
        for (char c : s) {
            if (isdigit(c)) {
                v = v * 10 + c - '0';
                continue;
            } else if (c == '[') {
                nums.push_back(v);
                v = 0;
            } else if (c == ']') {
                string str;
                while (strs.back() != "[") {
                    str += strs.back();
                    strs.pop_back();
                }
                strs.pop_back();
                strs.push_back(str);
                for (int i = 1; i < nums.back(); ++i) strs.back() += str;
                nums.pop_back();
                continue;
            }
            strs.push_back({c});
        }

        string result;
        for (string str : strs) {
            result += {str.rbegin(), str.rend()};
        }

        return result;
    }
};

class Solution {
   public:
    string decodeString(string s) {
        int i = 0;

        function<string()> decode = [&]() -> string {
            string result;
            int v = 0;

            while (i < s.size() && s[i] != ']') {
                if (isdigit(s[i])) {
                    v = v * 10 + s[i] - '0';
                } else if (s[i] == '[') {
                    ++i;
                    string res = decode();
                    while (v--) result += res;
                    v = 0;
                } else {
                    result += s[i];
                }
                ++i;
            }

            return result;
        };

        return decode();
    }
};
