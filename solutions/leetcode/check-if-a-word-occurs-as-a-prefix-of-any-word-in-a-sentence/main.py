class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        for i, w in enumerate(sentence.split()):
            if searchWord == w[: len(searchWord)]:
                return i + 1
        return -1
