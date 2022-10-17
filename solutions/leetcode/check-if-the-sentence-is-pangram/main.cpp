class Solution {
   public:
    bool checkIfPangram(string sentence) {
        array<int, 26> cnt;
        cnt.fill(0);

        for (char c : sentence) ++cnt[c - 'a'];

        for (int v : cnt) {
            if (v == 0) return false;
        }

        return true;
    }
};
