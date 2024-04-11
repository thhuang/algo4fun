class Solution:

    def removeKdigits(self, num: str, k: int) -> str:
        result = deque()
        for c in num:
            while k > 0 and len(result) > 0 and ord(result[-1]) > ord(c):
                result.pop()
                k -= 1
            result.append(c)

        for i in range(k):
            result.pop()

        while len(result) > 0 and result[0] == "0":
            result.popleft()

        return "".join(result) if len(result) > 0 else "0"
