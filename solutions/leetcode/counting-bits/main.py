class Solution:

    def countBits(self, n: int) -> List[int]:
        result = [0]

        b = 1
        while True:
            for i in range(b):
                if len(result) > n:
                    return result
                result.append(result[i] + 1)

            b = b << 1

        return []
