class Solution:

    def longestPalindrome(self, s: str) -> int:
        result = 0

        has_odd = False
        for v in Counter(s).values():
            if v % 2 == 1:
                has_odd = True
            result += v // 2 * 2

        if has_odd:
            result += 1

        return result


class Solution:

    def longestPalindrome(self, s: str) -> int:
        result = len(s)
        seen_odd = False
        for v in Counter(s).values():
            if v % 2 == 0:
                continue
            if seen_odd:
                result -= 1
            else:
                seen_odd = True
        return result
