class Solution:

    def calculateTime(self, keyboard: str, word: str) -> int:
        key_position = [None] * 26
        for i, k in enumerate(keyboard):
            key_position[ord(k) - ord('a')] = i
        result = 0
        p = 0
        for c in word:
            q = key_position[ord(c) - ord('a')]
            result += abs(p - q)
            p = q
        return result
