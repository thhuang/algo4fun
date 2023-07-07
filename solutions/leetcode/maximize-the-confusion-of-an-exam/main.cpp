class Solution {
    int maxConsecutive(string &s, char target, int k) {
        int result = 0;
        for (int l = 0, r = 0, diff = 0; r < s.size(); ++r) {
            if (s[r] != target) ++diff;
            while (diff > k) {
                if (s[l++] != target) --diff;
            }
            result = max(result, r - l + 1);
        }
        return result;
    }

   public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(maxConsecutive(answerKey, 'T', k),
                   maxConsecutive(answerKey, 'F', k));
    }
};
