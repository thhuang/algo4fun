class Solution:

    def lexicalOrder(self, n: int) -> List[int]:
        result = [1]
        while len(result) < n:
            v = result[-1] * 10
            while v > n:
                v = v // 10 + 1
                while v % 10 == 0:
                    v //= 10
            result.append(v)
        return result
