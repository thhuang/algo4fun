class Solution:

    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        pos, neg = [], []
        for d in [(v ^ k) - v for v in nums]:
            pos.append(d) if d > 0 else neg.append(d)

        result = sum(nums) + sum(pos)

        if len(pos) % 2 != 0:
            pos_min = min(pos)
            if len(neg) == 0:
                result -= pos_min
            else:
                neg_max = max(neg)
                if pos_min + neg_max >= 0:
                    result += neg_max
                else:
                    result -= pos_min

        return result
