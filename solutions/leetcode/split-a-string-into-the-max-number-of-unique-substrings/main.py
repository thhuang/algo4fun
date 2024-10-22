class Solution:

    def maxUniqueSplit(self, s: str) -> int:
        n = len(s)

        result = 0
        seen = set()

        def check(l: int) -> None:
            nonlocal result
            nonlocal seen

            if l == n:
                result = max(result, len(seen))
                return

            for r in range(l, n):
                t = s[l:r + 1]
                if t in seen:
                    continue
                seen.add(t)
                check(r + 1)
                seen.remove(t)

        check(0)

        return result
