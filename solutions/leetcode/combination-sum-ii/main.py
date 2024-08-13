class Solution:

    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        n = len(candidates)

        result = []
        curr = []
        s = 0

        def search(i: int):
            nonlocal result
            nonlocal curr
            nonlocal s

            if s > target:
                return
            if i == n:
                if s == target:
                    result.append(curr.copy())
                return

            v = candidates[i]

            curr.append(v)
            s += v
            search(i + 1)
            s -= v
            curr.pop()

            j = i + 1
            while j < n and candidates[j] == v:
                j += 1
            search(j)

        search(0)

        return result
