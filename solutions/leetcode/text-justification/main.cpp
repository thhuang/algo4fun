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
