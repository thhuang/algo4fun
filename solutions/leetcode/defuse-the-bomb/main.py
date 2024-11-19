class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        should_reverse = k < 0

        if should_reverse:
            code = code[::-1]
            k = -k

        result = [None] * n
        s = sum(code[:k])
        for i in reversed(range(n)):
            result[i] = s
            s = s + code[i] - code[(i + k) % n]

        if should_reverse:
            result = result[::-1]

        return result
