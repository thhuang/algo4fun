class Solution:

    def minimumDeletions(self, s: str) -> int:
        a = s.count("a")
        b = 0

        result = a + b
        for c in s:
            if c == "a":
                a -= 1
            else:  # c == "b"
                b += 1
            result = min(result, a + b)

        return result
