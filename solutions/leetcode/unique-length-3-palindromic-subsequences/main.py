class Solution:

    def countPalindromicSubsequence(self, s: str) -> int:
        char_indices = defaultdict(lambda: [])
        for i, c in enumerate(s):
            char_indices[c].append(i)

        result = 0

        for indices in char_indices.values():
            if len(indices) == 1:
                continue
            result += len(set(s[indices[0] + 1:indices[-1]]))

        return result
