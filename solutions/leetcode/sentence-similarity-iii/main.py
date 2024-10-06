class Solution:

    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        s1 = sentence1.split()
        s2 = sentence2.split()

        if len(s1) > len(s2):
            s1, s2 = s2, s1

        while len(s1) > 0 and s1[-1] == s2[-1]:
            s1.pop()
            s2.pop()

        if len(s1) == 0:
            return True

        for i in range(len(s1)):
            if s1[i] != s2[i]:
                return False

        return True
