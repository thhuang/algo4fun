class Solution:

    def increasingTriplet(self, nums: List[int]) -> bool:
        triplet = []
        for v in nums:
            i = bisect.bisect_left(triplet, v)
            if i == len(triplet):
                triplet.append(v)
            else:
                triplet[i] = v
            if len(triplet) == 3:
                return True
        return False
