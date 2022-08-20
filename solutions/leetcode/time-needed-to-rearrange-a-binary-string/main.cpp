class Solution {
   public:
    int secondsToRemoveOccurrences(string s) {
        int count = 0;
        while (true) {
            int swapped = false;
            for (int i = 0; i < s.size() - 1; ++i) {
                if (s[i] == '0' && s[i + 1] == '1') {
                    swapped = true;
                    swap(s[i], s[i + 1]);
                    ++i;
                }
            }
            if (!swapped) break;
            ++count;
        }
        return count;
    }
};
