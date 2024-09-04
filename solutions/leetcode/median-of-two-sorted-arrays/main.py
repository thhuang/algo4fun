class Solution:

    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        inf = float("inf")

        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1

        n1, n2 = len(nums1), len(nums2)
        n = n1 + n2
        l, r = -1, n1

        while l <= r:
            p1 = (l + r) // 2
            q1 = p1 + 1

            q2 = n // 2 - p1 - 1
            p2 = q2 - 1

            a1 = -inf if p1 < 0 else nums1[p1]
            b1 = inf if q1 >= n1 else nums1[q1]
            a2 = -inf if p2 < 0 else nums2[p2]
            b2 = inf if q2 >= n2 else nums2[q2]

            if a1 > b2:
                r = p1 - 1
            elif a2 > b1:
                l = p1 + 1
            else:
                if n % 2 == 1:
                    return min(b1, b2)
                else:
                    return (max(a1, a2) + min(b1, b2)) / 2

        return 0
