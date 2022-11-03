class Solution {
   public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();

        int result = 0;
        unordered_multiset<string> mids;
        unordered_multiset<string> rev;
        for (const string& w : words) {
            if (rev.count(w)) {
                rev.erase(rev.find(w));
                if (mids.count(w)) mids.erase(mids.find(w));
                result += 4;
            } else {
                string rw(w.rbegin(), w.rend());
                rev.insert(rw);
                if (w == rw) mids.insert(w);
            }
        }

        if (mids.empty()) return result;
        return result + 2;
    }
};
