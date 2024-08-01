class Solution:

    def circularArrayLoop(self, nums: List[int]) -> bool:

        def next(u: int) -> int:
            n = len(nums)
            return (u + nums[u] + n) % n

        def valid(u: int, v: int) -> bool:
            return u * v > 0

        vis = set()

        for i in range(len(nums)):
            if i in vis:
                continue
            slow = i
            fast = next(i)
            while valid(nums[slow], nums[fast]) and valid(nums[slow], nums[next(fast)]):
                if slow == fast:
                    if slow == next(slow):
                        break
                    return True
                vis.add(slow)
                slow = next(slow)
                fast = next(next(fast))

        return False
