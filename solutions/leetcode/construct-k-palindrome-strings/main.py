class Solution:

    def canConstruct(self, s: str, k: int) -> bool:
        if len(s) < k:
            return False

        odds = reduce(lambda acc, x: acc + x % 2, Counter(s).values(), 0)

        return odds <= k
