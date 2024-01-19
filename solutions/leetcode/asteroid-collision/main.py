class Solution:

    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        result = []

        for v in asteroids:
            if v > 0:
                result.append(v)
                continue

            while len(result) > 0:
                if result[-1] < 0 or result[-1] + v >= 0:
                    break
                result.pop()

            if len(result) == 0 or result[-1] < 0:
                result.append(v)
            elif result[-1] + v == 0:
                result.pop()

        return result
