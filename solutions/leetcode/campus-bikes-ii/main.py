class Solution:

    def assignBikes(self, workers: List[List[int]],
                    bikes: List[List[int]]) -> int:
        memo = defaultdict(lambda: -1)

        def dp(i: int, assigned: int) -> int:
            nonlocal memo

            if i == len(workers):
                return 0
            if memo[(i, assigned)] != -1:
                return memo[(i, assigned)]

            result = int(1e9)

            for j in range(0, len(bikes)):
                mask = (1 << j)
                if assigned & mask > 0:
                    continue
                d = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] -
                                                           bikes[j][1])

                result = min(result, d + dp(i + 1, assigned | mask))

            memo[(i, assigned)] = result
            return result

        return dp(0, 0)
