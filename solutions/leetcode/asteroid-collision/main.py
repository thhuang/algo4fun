class Solution:

    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        result = []

        for v in asteroids:
            while len(result) > 0 and 0 < result[-1] < -v:
                result.pop()

            if v > 0 or len(result) == 0 or result[-1] < 0:
                result.append(v)
            elif result[-1] + v == 0:
                result.pop()

        return result
