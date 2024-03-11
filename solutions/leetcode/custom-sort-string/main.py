class Solution:

    def customSortString(self, order: str, s: str) -> str:
        score = defaultdict(lambda: inf)
        for i, c in enumerate(order):
            score[c] = i
        return "".join(sorted(s, key=lambda c: score[c]))
