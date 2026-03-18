class Solution:

    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        while l <= r:
            m = (l + r) // 2
            if nums[m] <= nums[r] and (target < nums[m] or nums[r] < target):
                r = m - 1
            elif nums[m] > nums[r] and nums[r] < target < nums[m]:
                r = m - 1
            else:
                l = m + 1
        return r if nums[r] == target else -1


class Solution:

    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1

        while l <= r:
            m = (l + r) // 2
            if nums[l] <= nums[m] and nums[l] <= target <= nums[m]:
                r = m - 1
            elif nums[l] > nums[m] and (nums[l] <= target
                                        or target <= nums[m]):
                r = m - 1
            else:
                l = m + 1

        return l if l < len(nums) and target == nums[l] else -1


class Solution:

    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1

        while l <= r:
            m = (l + r) // 2
            if nums[m] == target:
                return m

            if nums[l] <= nums[m]:  # left half sorted
                if nums[l] <= target < nums[m]:
                    r = m - 1
                else:
                    l = m + 1
            else:  # right half sorted
                if nums[m] < target <= nums[r]:
                    l = m + 1
                else:
                    r = m - 1

        return -1
