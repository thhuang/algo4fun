class Solution:

    def customSortString(self, order: str, s: str) -> str:
        score = defaultdict(lambda: inf)
        for i, c in enumerate(order):
            score[c] = i
        return "".join(sorted(s, key=lambda c: score[c]))


class Solution:

    def customSortString(self, order: str, s: str) -> str:
        freq = Counter(s)
        result = []
        for c in order:
            n = freq[c]
            for _ in range(n):
                result.append(c)
                freq[c] -= 1
        for c, n in freq.items():
            for _ in range(n):
                result.append(c)
        return "".join(result)


class Solution:

    def customSortString(self, order: str, s: str) -> str:
        freq = Counter(s)
        result = []
        for c in order:
            for _ in range(freq[c]):
                result.append(c)
            freq[c] = 0
        for c, n in freq.items():
            for _ in range(n):
                result.append(c)
        return "".join(result)
