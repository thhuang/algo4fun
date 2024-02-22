class Solution:

    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        trust_count = [0] * n
        be_trusted_count = [0] * n
        for a, b in trust:
            trust_count[a - 1] += 1
            be_trusted_count[b - 1] += 1

        for i in range(n):
            if trust_count[i] == 0 and be_trusted_count[i] == n - 1:
                return i + 1

        return -1
