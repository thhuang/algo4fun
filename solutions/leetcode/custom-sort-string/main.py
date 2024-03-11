class Solution:

    def customSortString(self, order: str, s: str) -> str:
        score = defaultdict(lambda: inf)
        for i, c in enumerate(order):
            score[c] = i
        return "".join(sorted(s, key=lambda c: score[c]))


class Solution:

    def customSortString(self, order: str, s: str) -> str:
        freq = defaultdict(int)
        for c in s:
            freq[c] += 1

        result = []
        for c in order:
            for i in range(freq[c]):
                result.append(c)
            freq[c] = 0

        for c, f in freq.items():
            for i in range(f):
                result.append(c)

        return "".join(result)
