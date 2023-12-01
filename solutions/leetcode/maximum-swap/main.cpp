class Solution {
   public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int result = num;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i + 1; j < s.size(); ++j) {
                if (i == j) {
                    continue;
                }
                swap(s[i], s[j]);
                result = max(result, stoi(s));
                swap(s[i], s[j]);
            }
        }
        return result;
    }
};
