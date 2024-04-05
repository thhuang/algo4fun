class Solution:

    def lengthOfLongestSubstringTwoDistinct(self, s: str) -> int:
        freq = defaultdict(int)
        cnt = 0
        result = 0
        l = 0
        for r in range(len(s)):
            freq[s[r]] += 1
            if freq[s[r]] == 1:
                cnt += 1
            while cnt > 2:
                freq[s[l]] -= 1
                if freq[s[l]] == 0:
                    cnt -= 1
                l += 1
            result = max(result, r - l + 1)
        return result
