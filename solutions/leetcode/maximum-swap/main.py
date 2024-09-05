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


class Solution:

    def maximumSwap(self, num: int) -> int:
        s = [c for c in str(num)]

        l = None
        r_val = None

        mx = 0
        for i in range(len(s))[::-1]:
            v = int(s[i])
            if v < mx:
                l = i
                r_val = mx

            mx = max(mx, v)

        if l is None:
            return num

        for r in range(len(s))[::-1]:
            if int(s[r]) == r_val:
                s[l], s[r] = s[r], s[l]
                break

        return int("".join(s))
