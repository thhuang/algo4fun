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

class Solution {
   public:
    string removeKdigits(string num, int k) {
        string result;
        for (char c : num) {
            while (k > 0 && !result.empty() && result.back() > c) {
                result.pop_back();
                --k;
            }
            result.push_back(c);
        }

        while (k--) result.pop_back();

        auto it = find_if(result.begin(), result.end(),
                          [](char c) -> bool { return c != '0'; });

        return it == result.end() ? "0" : string(it, result.end());
    }
};
