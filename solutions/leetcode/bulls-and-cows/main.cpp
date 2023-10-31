class Solution {
   public:
    string getHint(string secret, string guess) {
        int n = secret.size();

        unordered_map<char, int> digitFreq;
        int a = 0, b = 0;

        for (int i = 0; i < n; ++i) {
            if (secret[i] == guess[i]) {
                ++a;
            } else {
                if (++digitFreq[secret[i]] <= 0) ++b;
                if (--digitFreq[guess[i]] >= 0) ++b;
            }
        }

        return to_string(a) + "A" + to_string(b) + "B";
    }
};
