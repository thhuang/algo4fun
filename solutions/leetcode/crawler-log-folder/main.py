class Solution:

    def minOperations(self, logs: List[str]) -> int:
        result = 0
        for s in logs:
            if s == "../":
                result = max(0, result - 1)
            elif s != "./":
                result += 1
        return result
