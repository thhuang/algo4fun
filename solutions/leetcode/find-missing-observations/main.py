class Solution:

    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        m = len(rolls)
        total = mean * (m + n)

        result = [1] * n
        target = total - sum(rolls) - n
        if target < 0 or n * 5 < target:
            return []

        six_count = target // 5
        rem = target % 5

        for i in range(six_count):
            result[i] = 6
        if rem > 0:
            result[six_count] += rem

        return result
