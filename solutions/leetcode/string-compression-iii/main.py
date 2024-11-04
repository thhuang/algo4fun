class Solution:

    def compressedString(self, word: str) -> str:
        compressed = []
        l = 0
        while l < len(word):
            r = l + 1
            while r < len(word) and word[r] == word[l] and r - l < 9:
                r += 1
            compressed.append(f'{r - l}{word[l]}')
            l = r
        return "".join(compressed)
