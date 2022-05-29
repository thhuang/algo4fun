class Solution {
   public:
    bool digitCount(string num) {
        unordered_map<int, int> count;
        for (char c : num) ++count[c - '0'];

        for (int i = 0; i < num.size(); ++i) {
            if (count[i] != (num[i] - '0')) return false;
        }

        return true;
    }
};
