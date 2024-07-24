class Solution:

    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:

        def mp(num: int) -> int:
            lst = [int(c) for c in str(num)]
            mapped_lst = map(lambda v: mapping[v], lst)
            return reduce(lambda a, b: a * 10 + b, mapped_lst)

        order = sorted(list(enumerate(nums)), key=lambda v: (mp(v[1]), v[0]))

        return [v[1] for v in order]
