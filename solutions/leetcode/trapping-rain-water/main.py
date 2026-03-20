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


class Solution:

    def trap(self, height: List[int]) -> int:
        n = len(height)
        result = 0

        water = [0] * n

        mx = 0
        for i in range(n):
            mx = max(mx, height[i])
            water[i] = mx

        mx = 0
        for i in range(n)[::-1]:
            mx = max(mx, height[i])
            result += min(water[i], mx) - height[i]

        return result
