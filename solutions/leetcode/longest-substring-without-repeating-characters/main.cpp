class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_set<char> seen;
        for (int l = 0, r = 0; r < size(s); ++r) {
            while (seen.count(s[r])) {
                seen.erase(s[l++]);
            }
            seen.insert(s[r]);
            ans = max(ans, int(size(seen)));
        }
        return ans;
    }
};

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        unordered_map<char, bool> seen;
        for (int l = 0, r = 0; r < s.size(); ++r) {
            while (seen[s[r]]) seen[s[l++]] = false;
            seen[s[r]] = true;
            result = max(result, r - l + 1);
        }
        return result;
    }
};

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        unordered_map<char, int> lastPosPlusOne;
        for (int l = 0, r = 0; r < s.size(); ++r) {
            l = max(l, lastPosPlusOne[s[r]]);
            result = max(result, r - l + 1);
            lastPosPlusOne[s[r]] = r + 1;
        }
        return result;
    }
};
