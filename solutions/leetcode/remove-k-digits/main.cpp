class Solution {
   public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        deque<char> remains(num.begin(), num.end());
        int i = 0;
        while (remains.size() > n - k) {
            if (i + 1 == remains.size()) {
                remains.pop_back();
                --i;
            } else if (remains[i] > remains[i + 1]) {
                remains.erase(remains.begin() + i);
                if (i != 0) --i;
            } else {
                ++i;
            }
        }

        while (!remains.empty() && remains.front() == '0') remains.pop_front();

        return remains.empty() ? "0" : string(remains.begin(), remains.end());
    }
};
