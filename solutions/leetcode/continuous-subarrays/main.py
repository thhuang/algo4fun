class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        result = 0

        inc = deque()
        dec = deque()

        l = 0
        for r in range(len(nums)):
            while len(inc) > 0 and inc[-1] > nums[r]:
                inc.pop()
            inc.append(nums[r])

            while len(dec) > 0 and dec[-1] < nums[r]:
                dec.pop()
            dec.append(nums[r])

            while dec[0] - inc[0] > 2:
                if nums[l] == inc[0]:
                    inc.popleft()
                if nums[l] == dec[0]:
                    dec.popleft()
                l += 1

            result += r - l + 1

        return result
