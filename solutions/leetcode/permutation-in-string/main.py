class Solution:

    def checkInclusion(self, s1: str, s2: str) -> bool:
        idx = lambda c: ord(c) - ord("a")

        t = [0] * 26
        for c in s1:
            t[idx(c)] += 1

        window = [0] * 26
        for r in range(len(s2)):
            window[idx(s2[r])] += 1
            l = r - len(s1)
            if l >= 0:
                window[idx(s2[l])] -= 1
            if window == t:
                return True
            print(r, window)

        return False
