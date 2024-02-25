class Solution:

    def getDivisors(self, num) -> List[int]:
        result = []
        for i in range(2, int(sqrt(num)) + 1):
            if num % i != 0:
                continue
            result.append(i)
            if i * i != num:
                result.append(num // i)
        return result

    def canTraverseAllPairs(self, nums: List[int]) -> bool:
        if len(nums) < 2:
            return True
        if 1 in nums:
            return False

        group = list(range(max(nums) + 1))
        rank = [0] * (max(nums) + 1)

        def find(x):
            if group[x] == x:
                return x
            group[x] = find(group[x])
            return group[x]

        def unite(a, b):
            ga, gb = find(a), find(b)
            if ga == gb:
                return
            if rank[ga] < rank[gb]:
                group[ga] = gb
            elif rank[gb] < rank[ga]:
                group[gb] = ga
            else:
                rank[gb] += 1
                group[ga] = gb

        for num in nums:
            for v in self.getDivisors(num):
                unite(num, v)

        return len(set([find(num) for num in nums])) == 1
