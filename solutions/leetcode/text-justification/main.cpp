class Solution {
   public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        vector<string> line;
        int len = 0;

        auto print = [&]() -> void {
            if (line.size() == 1) {
                string s =
                    line.front() + string(maxWidth - line.front().size(), ' ');
                result.push_back(s);
            } else {
                int sp = maxWidth - len;
                int base = sp / (line.size() - 1);
                int extra = sp % (line.size() - 1);

                result.push_back(line.front());
                for (int i = 1; i < line.size(); ++i) {
                    int v = base;
                    if (--extra >= 0) ++v;
                    result.back() += string(v, ' ') + line[i];
                }
            }

            line.clear();
            len = 0;
        };

        for (const string& w : words) {
            if (len + w.size() + line.size() > maxWidth) print();
            line.push_back(w);
            len += w.size();
        }

        result.push_back(line.front());
        for (int i = 1; i < line.size(); ++i)
            result.back() = result.back() + " " + line[i];
        result.back() += string(maxWidth - result.back().size(), ' ');

        return result;
    }
};

class Solution {
   public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        auto generate = [&](int l, int r) -> string {
            int spaces = maxWidth;
            for (int i = l; i < r; ++i) spaces -= words[i].size();

            int cnt = r - l - 1;
            if (cnt == 0) return words[l] + string(spaces, ' ');

            int pad = spaces / cnt;
            int rem = spaces % cnt;

            string result;
            for (int i = l; i < r - 1; ++i) {
                result += words[i] + string(pad + (rem-- > 0), ' ');
            }
            result += words[r - 1];

            return result;
        };

        vector<string> result;
        int n = words.size();
        for (int l = 0; l < n;) {
            int r = l + 1, cnt = words[l].size();
            while (r < n) {
                cnt += 1 + words[r].size();
                if (cnt > maxWidth) break;
                ++r;
            }

            if (r < n) {
                result.push_back(generate(l, r));
            } else {
                string s = words[l];
                for (int i = l + 1; i < r; ++i) s += " " + words[i];
                s += string(maxWidth - s.size(), ' ');
                result.push_back(s);
            }

            l = r;
        }

        return result;
    }
};
