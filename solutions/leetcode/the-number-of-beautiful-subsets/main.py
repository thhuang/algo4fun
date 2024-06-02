class Solution:

    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        result = -1
        curr = []

        def search(i):
            nonlocal result
            nonlocal curr

            if i == len(nums):
                result += 1
                return

            search(i + 1)

            for j in curr:
                if abs(nums[j] - nums[i]) == k:
                    return

            curr.append(i)
            search(i + 1)
            curr.pop()

        search(0)

        return result
