class Solution:

    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        happiness.sort(key=lambda v: -v)
        result = 0
        for i, v in enumerate(happiness[:k]):
            result += max(0, v - i)
        return result
