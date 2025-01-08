class Solution:

    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        result = 0

        for i in range(len(words)):
            for j in range(i + 1, len(words)):
                n = len(words[i])
                if words[i] == words[j][:n] and words[i] == words[j][-n:]:
                    result += 1

        return result
