class Solution {
   public:
    string removeDigit(string number, char digit) {
        auto gen = [&number](int pos) {
            string s;
            for (int i = 0; i < number.size(); ++i) {
                if (i == pos) continue;
                s += number[i];
            }
            return s;
        };

        vector<int> idxs;
        for (int i = 0; i < number.size(); ++i) {
            if (number[i] == digit) {
                idxs.push_back(i);
                if (i + 1 < number.size() && number[i] < number[i + 1]) {
                    return gen(i);
                }
            }
        }

        return gen(idxs.back());
    }
};
