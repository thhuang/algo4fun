class Solution:

    def minOperations(self, boxes: str) -> List[int]:
        balls = [int(b) for b in boxes]
        left = self.operationsFromLeft(balls)
        right = self.operationsFromLeft(balls[::-1])[::-1]
        return [l + r for l, r in zip(left, right)]

    def operationsFromLeft(self, balls: List[int]) -> List[int]:
        n = len(balls)
        result = [0] * n
        seen = balls[0]
        for i in range(1, n):
            result[i] = result[i - 1] + seen
            seen += balls[i]
        return result
