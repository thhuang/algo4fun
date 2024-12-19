class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        mn, mx = 0, 0
        l, r = 0, 0
        result = 0

        while l < len(arr):
            mx = max(mx, arr[l])

            r = l + 1
            while r < len(arr) and mx - mn + 1 > r - l:
                mx = max(mx, arr[r])
                r += 1

            result += 1
            mn = mx + 1
            l = r

        return result
