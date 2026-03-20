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


class Solution:

    def trap(self, height: List[int]) -> int:
        n = len(height)
        result = 0

        p_mx = 0
        mx = 0
        for i, h in enumerate(height):
            if h > mx:
                mx = h
                p_mx = i

        result = 0

        i = 0
        h = 0
        while i < p_mx:
            h = max(h, height[i])
            result += h - height[i]
            i += 1

        i = n - 1
        h = 0
        while i > p_mx:
            h = max(h, height[i])
            result += h - height[i]
            i -= 1

        return result


class Solution:

    def trap(self, height: List[int]) -> int:
        peak = height.index(max(height))
        result = 0

        def sweep(rng):
            nonlocal result
            mx = 0
            for i in rng:
                mx = max(mx, height[i])
                result += mx - height[i]

        sweep(range(0, peak))
        sweep(range(len(height) - 1, peak, -1))

        return result
