class Solution:

    def __init__(self):
        self.vowels = {"a", "e", "i", "o", "u"}

    def vowelStrings(self, words: List[str],
                     queries: List[List[int]]) -> List[int]:
        suffix_sum = [0] * (len(words) + 1)
        for i in reversed(range(len(words))):
            suffix_sum[i] = suffix_sum[i + 1]
            if words[i][0] in self.vowels and words[i][-1] in self.vowels:
                suffix_sum[i] += 1

        return [suffix_sum[l] - suffix_sum[r + 1] for l, r in queries]
