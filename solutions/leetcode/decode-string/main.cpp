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

class Solution {
   public:
    string decodeString(string s) {
        int i = 0;

        function<string()> decode = [&]() -> string {
            string result;

            while (i < s.size() && s[i] != ']') {
                if (!isdigit(s[i])) {
                    result += s[i++];
                    continue;
                }

                int v = 0;
                while (isdigit(s[i])) v = v * 10 + s[i++] - '0';

                ++i;
                string res = decode();
                while (v--) result += res;
                ++i;
            }

            return result;
        };

        return decode();
    }
};

class Solution {
   public:
    string decodeString(string s) {
        function<string(int&)> decode = [&](int& i) -> string {
            string result;

            for (; i < s.size() && s[i] != ']'; ++i) {
                if (isalpha(s[i])) {
                    result += s[i];
                } else {  // isdigit(s[i])
                    int n = 0;
                    for (; s[i] != '['; ++i) n = n * 10 + (s[i] - '0');
                    string sub = decode(++i);
                    for (int j = 0; j < n; ++j) result += sub;
                }
            }

            return result;
        };

        int i = 0;
        return decode(i);
    }
};

class Solution {
   public:
    string decodeString(string s) {
        int p = 0;

        function<string()> parse = [&]() -> string {
            string result;
            int v = 0;
            while (p < s.size()) {
                char c = s[p];
                if (isdigit(c)) {
                    v = v * 10 + (c - '0');
                    ++p;
                } else if (c == '[') {
                    ++p;
                    string sub = parse();
                    for (int i = 0; i < v; ++i) result += sub;
                    v = 0;
                } else if (c == ']') {
                    ++p;
                    break;
                } else {
                    result += c;
                    ++p;
                }
            }
            return result;
        };

        return parse();
    }
};
