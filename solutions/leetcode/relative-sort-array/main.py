class Solution:

    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        order = dict()
        for i, v in enumerate(arr2):
            order[v] = i

        r = []
        l = []

        for v in arr1:
            if v in order:
                l.append(v)
            else:
                r.append(v)

        return sorted(l, key=lambda v: order[v]) + sorted(r)
