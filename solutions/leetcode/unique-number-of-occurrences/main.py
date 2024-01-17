class Solution:

    def uniqueOccurrences(self, arr: List[int]) -> bool:
        freq = collections.Counter(arr)
        occurrence_freq = collections.Counter(freq.values())
        for v in occurrence_freq.values():
            if v > 1:
                return False
        return True


class Solution:

    def uniqueOccurrences(self, arr: List[int]) -> bool:
        freq = collections.Counter(arr)
        occurrence_freq = collections.Counter(freq.values())
        occurrences = set(occurrence_freq.values())
        if 1 not in occurrences or len(occurrences) > 1:
            return False
        return True
