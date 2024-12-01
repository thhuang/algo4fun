class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        seen = set()
        for v in arr:
            if v / 2 in seen or v * 2 in seen:
                return True
            seen.add(v)
        return False
