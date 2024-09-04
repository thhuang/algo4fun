class Solution:

    def maxArea(self, height: List[int]) -> int:
        result = 0

        l, r = 0, len(height) - 1
        while l < r:
            hl, hr = height[l], height[r]
            h = min(hl, hr)
            result = max(result, h * (r - l))
            if h == hl:
                l += 1
            else:  # h == hr
                r -= 1

        return result
