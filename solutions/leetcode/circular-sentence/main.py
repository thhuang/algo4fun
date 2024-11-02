class Solution:

    def isCircularSentence(self, sentence: str) -> bool:
        words = sentence.split()
        for i in range(len(words)):
            if words[i][0] != words[i - 1][-1]:
                return False
        return True
