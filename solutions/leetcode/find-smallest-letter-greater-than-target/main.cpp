class Solution {
   public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto it = upper_bound(letters.begin(), letters.end(), target);
        if (it == letters.end()) return letters[0];
        return *it;
    }
};

class Solution {
   public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = -1, r = letters.size();
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (letters[m] <= target) {
                l = m;
            } else {
                r = m;
            }
        }
        return letters[r % letters.size()];
    }
};
