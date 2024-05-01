class Solution:

    def reversePrefix(self, word: str, ch: str) -> str:
        if ch not in word:
            return word
        r = word.index(ch) + 1
        return word[:r][::-1] + word[r:]
