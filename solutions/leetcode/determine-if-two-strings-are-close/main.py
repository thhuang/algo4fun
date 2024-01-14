class Solution:

    def closeStrings(self, word1: str, word2: str) -> bool:
        if len(word1) != len(word2):
            return False

        if set(word1) != set(word2):
            return False

        charfreq1 = Counter(word1)
        charfreq2 = Counter(word2)
        freqcount1 = Counter(charfreq1.values())
        freqcount2 = Counter(charfreq2.values())

        return freqcount1 == freqcount2
