class Solution:

    def pathSum(self, nums: List[int]) -> int:
        tree = dict()
        for v in nums:
            lv = v // 100
            pos = v % 100 // 10
            val = v % 10
            tree[(lv, pos)] = val

        def dfs(lv, pos) -> Tuple[int, int]:
            if (lv, pos) not in tree:
                return (0, 0)
            if lv == 4:
                return (tree[(lv, pos)], 1)

            l = dfs(lv + 1, pos * 2 - 1)
            r = dfs(lv + 1, pos * 2)
            cnt = max(1, l[1] + r[1])
            v = tree[(lv, pos)] * cnt
            return (v + l[0] + r[0], cnt)

        return dfs(1, 1)[0]
