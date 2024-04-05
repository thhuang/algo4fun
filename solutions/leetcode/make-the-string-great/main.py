class Solution:

    def makeGood(self, s: str) -> str:
        bad_pairs = dict()
        for i in range(26):
            bad_pairs[chr(ord("a") + i)] = chr(ord("A") + i)
            bad_pairs[chr(ord("A") + i)] = chr(ord("a") + i)

        result = []
        for c in s:
            if len(result) > 0 and bad_pairs[c] == result[-1]:
                result.pop()
            else:
                result.append(c)

        return "".join(result)


class Solution:

    def makeGood(self, s: str) -> str:
        result = []
        for c in s:
            if len(result) > 0 and ((c.isupper() and c.lower() == result[-1]) or
                                    c.islower() and c.upper() == result[-1]):
                result.pop()
            else:
                result.append(c)

        return "".join(result)
