class Solution:

    def combinationSum(self, candidates: List[int],
                       target: int) -> List[List[int]]:
        result = []

        combination = []
        s = 0

        def search(i: int) -> None:
            nonlocal s

            if i == len(candidates):
                if s == target:
                    result.append(combination.copy())
                return

            search(i + 1)

            cnt = 0
            while s <= target:
                combination.append(candidates[i])
                s += candidates[i]

                search(i + 1)

                cnt += 1

            for _ in range(cnt):
                combination.pop()
                s -= candidates[i]

        search(0)

        return result
