class Solution:

    def kthDistinct(self, arr: List[str], k: int) -> str:
        freq = Counter(arr)
        for s in arr:
            if freq[s] == 1:
                k -= 1
                if k == 0:
                    return s
        return ""
