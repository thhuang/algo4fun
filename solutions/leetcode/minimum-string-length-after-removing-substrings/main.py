class Solution:

    def minLength(self, s: str) -> int:
        arr = []
        for c in s:
            arr.append(c)
            while len(arr) >= 2 and (arr[-2:] in (["A", "B"], ["C", "D"])):
                arr.pop()
                arr.pop()
        return len(arr)
