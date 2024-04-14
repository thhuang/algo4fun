class Solution:

    def verifyPreorder(self, preorder: List[int]) -> bool:
        min_limit = -inf
        desc = []

        for i, v in enumerate(preorder):
            while len(desc) > 0 and desc[-1] < v:
                min_limit = max(min_limit, desc.pop())
            if v < min_limit:
                return False
            desc.append(v)

        return True
