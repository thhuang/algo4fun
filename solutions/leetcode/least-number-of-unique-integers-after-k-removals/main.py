from itertools import accumulate
from collections import Counter
from bisect import bisect_right


class Solution:

    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        freqs = sorted(Counter(arr).values())
        accu = list(accumulate(freqs))
        return len(accu) - bisect_right(accu, k)
