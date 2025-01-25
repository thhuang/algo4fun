class Solution:

    def lexicographicallySmallestArray(self, nums: List[int],
                                       limit: int) -> List[int]:
        n = len(nums)
        sorted_nums = sorted(nums)

        group_nums = [deque([sorted_nums[0]])]
        num_to_group = {sorted_nums[0]: 0}

        for i in range(1, n):
            num = sorted_nums[i]
            if num - group_nums[-1][-1] > limit:
                group_nums.append(deque())

            group_nums[-1].append(num)
            num_to_group[num] = len(group_nums) - 1

        result = []
        for num in nums:
            group = num_to_group[num]
            v = group_nums[group].popleft()
            result.append(v)

        return result
