class Solution:

    def maximumSwap(self, num: int) -> int:
        s = str(num)
        result = num
        for i in range(len(s)):
            for j in range(i + 1, len(s)):
                if i == j:
                    continue
                t = s[0:i] + s[j] + s[i + 1:j] + s[i] + s[j + 1:]
                result = max(result, int(t))
        return result
