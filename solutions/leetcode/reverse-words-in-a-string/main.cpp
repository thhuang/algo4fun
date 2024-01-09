class Solution {
   public:
    string reverseWords(string s) {
        string t;
        for (char c : s) {
            if (!t.empty() && t.back() == ' ' && c == ' ') {
                continue;
            } else if (t.empty() && c == ' ') {
                continue;
            } else {
                t += c;
            }
        }

        if (!t.empty() && t.back() == ' ') t.pop_back();

        reverse(t.begin(), t.end());

        for (int l = 0, r = 0; r <= t.size(); ++r) {
            if (r < t.size() && t[r] != ' ') continue;
            reverse(t.begin() + l, t.begin() + r);
            l = r + 1;
        }

        return t;
    }
};

class Solution {
   public:
    string reverseWords(string s) {
        int n = s.size();

        string result;

        reverse(s.begin(), s.end());
        for (int l = 0; l < s.size(); ++l) {
            if (s[l] == ' ') continue;
            int r = l + 1;
            while (r < s.size() && s[r] != ' ') ++r;
            string w = s.substr(l, r - l);
            reverse(w.begin(), w.end());
            result += w + " ";
            l = r;
        }

        result.pop_back();

        return result;
    }
};

class Solution {
   public:
    string reverseWords(string s) {
        int p = 0;
        reverse(s.begin(), s.end());
        for (int l = 0; l < s.size(); ++l) {
            if (s[l] == ' ') continue;
            int r = l + 1;
            while (r < s.size() && s[r] != ' ') ++r;
            reverse(s.begin() + l, s.begin() + r);
            for (int i = l; i < r; ++i) s[p++] = s[i];
            s[p++] = ' ';
            l = r - 1;
        }
        return s.substr(0, p - 1);
    }
};

class Solution {
   public:
    string reverseWords(string s) {
        string t;
        for (char c : string{s.rbegin(), s.rend()}) {
            if (c == ' ' && (t.empty() || t.back() == ' ')) {
                continue;
            }
            t.push_back(c);
        }
        if (t.back() == ' ') {
            t.pop_back();
        }

        for (int l = 0; l < t.size(); ++l) {
            int r = l;
            while (r < t.size() && t[r] != ' ') {
                ++r;
            }
            reverse(t.begin() + l, t.begin() + r);
            l = r;
        }

        return t;
    }
};
