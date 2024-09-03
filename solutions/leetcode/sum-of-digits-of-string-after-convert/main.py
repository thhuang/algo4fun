class Solution:

    def getLucky(self, s: str, k: int) -> int:
        t = "".join([str(ord(c) - ord('a') + 1) for c in s])

        for _ in range(k):
            t = str(reduce(lambda v, s: int(s) + v, t, 0))

        return int(t)
