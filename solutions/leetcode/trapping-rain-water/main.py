class Solution:

    def trap(self, height: List[int]) -> int:
        n = len(height)
        trapping_height = [0] * n

        l = 0
        for i, v in enumerate(height):
            l = max(l, v)
            trapping_height[i] = l

        r = 0
        for i in reversed(range(n)):
            r = max(r, height[i])
            trapping_height[i] = min(trapping_height[i], r)

        result = 0
        for i in range(n):
            result += trapping_height[i] - height[i]

        return result


class Solution:

    def trap(self, height: List[int]) -> int:
        n = len(height)
        trapping_height = [0] * n

        l = 0
        for i, v in enumerate(height):
            l = max(l, v)
            trapping_height[i] = l

        result = 0
        r = 0
        for i in reversed(range(n)):
            r = max(r, height[i])
            result += min(trapping_height[i], r) - height[i]

        return result
